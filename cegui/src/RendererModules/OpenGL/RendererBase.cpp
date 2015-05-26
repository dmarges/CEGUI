/***********************************************************************
    created:    Tue Apr 30 2013
    authors:    Paul D Turner <paul@cegui.org.uk>
                Lukas E Meindl
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2013 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#include "CEGUI/RendererModules/OpenGL/RendererBase.h"
#include "CEGUI/RendererModules/OpenGL/Texture.h"
#include "CEGUI/RendererModules/OpenGL/TextureTarget.h"
#include "CEGUI/RendererModules/OpenGL/ViewportTarget.h"
#include "CEGUI/RendererModules/OpenGL/GeometryBufferBase.h"
#include "CEGUI/Exceptions.h"
#include "CEGUI/ImageCodec.h"
#include "CEGUI/DynamicModule.h"
#include "CEGUI/System.h"
#include "CEGUI/Logger.h"

#include <sstream>
#include <algorithm>

namespace CEGUI
{
//----------------------------------------------------------------------------//
String OpenGLRendererBase::d_rendererID("--- subclass did not set ID: Fix this!");

//----------------------------------------------------------------------------//
OpenGLRendererBase::OpenGLRendererBase() :
    d_displayDPI(96, 96),
    d_initExtraStates(false),
    d_activeBlendMode(BM_INVALID)
{
    initialiseMaxTextureSize();
    initialiseDisplaySizeWithViewportSize();

    d_defaultTarget = new OpenGLViewportTarget(*this);
}

//----------------------------------------------------------------------------//
OpenGLRendererBase::OpenGLRendererBase(const Sizef& display_size) :
    d_displaySize(display_size),
    d_displayDPI(96, 96),
    d_initExtraStates(false),
    d_activeBlendMode(BM_INVALID)
{
    initialiseMaxTextureSize();

    d_defaultTarget = new OpenGLViewportTarget(*this);
}

//----------------------------------------------------------------------------//
OpenGLRendererBase::~OpenGLRendererBase()
{
    destroyAllGeometryBuffers();
    destroyAllTextureTargets();
    destroyAllTextures();

    delete d_defaultTarget;
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::initialiseDisplaySizeWithViewportSize()
{
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    d_displaySize = Sizef(static_cast<float>(vp[2]),
                          static_cast<float>(vp[3]));
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::initialiseMaxTextureSize()
{
    GLint max_tex_size;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex_size);
    d_maxTextureSize = max_tex_size;
}

//----------------------------------------------------------------------------//
RenderTarget& OpenGLRendererBase::getDefaultRenderTarget()
{
    return *d_defaultTarget;
}

//----------------------------------------------------------------------------//
GeometryBuffer& OpenGLRendererBase::createGeometryBufferTextured(CEGUI::RefCounted<RenderMaterial> renderMaterial)
{
    OpenGLGeometryBufferBase* geom_buffer = createGeometryBuffer_impl(renderMaterial);

    geom_buffer->addVertexAttribute(VAT_POSITION0);
    geom_buffer->addVertexAttribute(VAT_COLOUR0);
    geom_buffer->addVertexAttribute(VAT_TEXCOORD0);
    geom_buffer->finaliseVertexAttributes();

    addGeometryBuffer(*geom_buffer);
    return *geom_buffer;
}

//----------------------------------------------------------------------------//
GeometryBuffer& OpenGLRendererBase::createGeometryBufferColoured(CEGUI::RefCounted<RenderMaterial> renderMaterial)
{
    OpenGLGeometryBufferBase* geom_buffer = createGeometryBuffer_impl(renderMaterial);

    geom_buffer->addVertexAttribute(VAT_POSITION0);
    geom_buffer->addVertexAttribute(VAT_COLOUR0);
    geom_buffer->finaliseVertexAttributes();

    addGeometryBuffer(*geom_buffer);
    return *geom_buffer;
}


//----------------------------------------------------------------------------//
TextureTarget* OpenGLRendererBase::createTextureTarget()
{
    TextureTarget* t = createTextureTarget_impl();

    if (t)
        d_textureTargets.push_back(t);

    return t;
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::destroyTextureTarget(TextureTarget* target)
{
    TextureTargetList::iterator i = std::find(d_textureTargets.begin(),
                                              d_textureTargets.end(),
                                              target);

    if (d_textureTargets.end() != i)
    {
        d_textureTargets.erase(i);
        delete target;
    }
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::destroyAllTextureTargets()
{
    while (!d_textureTargets.empty())
        destroyTextureTarget(*d_textureTargets.begin());
}

//----------------------------------------------------------------------------//
Texture& OpenGLRendererBase::createTexture(const String& name)
{
    if (d_textures.find(name) != d_textures.end())
        CEGUI_THROW(AlreadyExistsException(
            "A texture named '" + name + "' already exists."));

    OpenGLTexture* tex = createTexture_impl(name);
    tex->initialise();
    d_textures[name] = tex;

    logTextureCreation(name);

    return *tex;
}

//----------------------------------------------------------------------------//
Texture& OpenGLRendererBase::createTexture(const String& name,
                                       const String& filename,
                                       const String& resourceGroup)
{
    if (d_textures.find(name) != d_textures.end())
        CEGUI_THROW(AlreadyExistsException(
            "A texture named '" + name + "' already exists."));

    OpenGLTexture* tex = createTexture_impl(name);
    tex->initialise(filename, resourceGroup);
    d_textures[name] = tex;

    logTextureCreation(name);

    return *tex;
}

//----------------------------------------------------------------------------//
Texture& OpenGLRendererBase::createTexture(const String& name, const Sizef& size)
{
    if (d_textures.find(name) != d_textures.end())
        CEGUI_THROW(AlreadyExistsException(
            "A texture named '" + name + "' already exists."));

    OpenGLTexture* tex = createTexture_impl(name);
    tex->initialise(size);
    d_textures[name] = tex;

    logTextureCreation(name);

    return *tex;
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::logTextureCreation(const String& name)
{
    Logger* logger = Logger::getSingletonPtr();
    if (logger)
        logger->logEvent("[OpenGLRenderer] Created texture: " + name);
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::destroyTexture(Texture& texture)
{
    destroyTexture(texture.getName());
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::destroyTexture(const String& name)
{
    TextureMap::iterator i = d_textures.find(name);

    if (d_textures.end() != i)
    {
        logTextureDestruction(name);
        delete i->second;
        d_textures.erase(i);
    }
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::logTextureDestruction(const String& name)
{
    Logger* logger = Logger::getSingletonPtr();
    if (logger)
        logger->logEvent("[OpenGLRenderer] Destroyed texture: " + name);
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::destroyAllTextures()
{
    while (!d_textures.empty())
        destroyTexture(d_textures.begin()->first);
}

//----------------------------------------------------------------------------//
Texture& OpenGLRendererBase::getTexture(const String& name) const
{
    TextureMap::const_iterator i = d_textures.find(name);
    
    if (i == d_textures.end())
        CEGUI_THROW(UnknownObjectException(
            "No texture named '" + name + "' is available."));

    return *i->second;
}

//----------------------------------------------------------------------------//
bool OpenGLRendererBase::isTextureDefined(const String& name) const
{
    return d_textures.find(name) != d_textures.end();
}

//----------------------------------------------------------------------------//
const Sizef& OpenGLRendererBase::getDisplaySize() const
{
    return d_displaySize;
}

//----------------------------------------------------------------------------//
const glm::vec2& OpenGLRendererBase::getDisplayDPI() const
{
    return d_displayDPI;
}

//----------------------------------------------------------------------------//
uint OpenGLRendererBase::getMaxTextureSize() const
{
    return d_maxTextureSize;
}

//----------------------------------------------------------------------------//
const String& OpenGLRendererBase::getIdentifierString() const
{
    return d_rendererID;
}

//----------------------------------------------------------------------------//
Texture& OpenGLRendererBase::createTexture(const String& name, GLuint tex,
                                       const Sizef& sz)
{
    if (d_textures.find(name) != d_textures.end())
        CEGUI_THROW(AlreadyExistsException(
            "A texture named '" + name + "' already exists."));

    OpenGLTexture* t = createTexture_impl(name);
    t->initialise(tex, sz);
    d_textures[name] = t;

    logTextureCreation(name);

    return *t;
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::setDisplaySize(const Sizef& sz)
{
    if (sz != d_displaySize)
    {
        d_displaySize = sz;

        // update the default target's area
        Rectf area(d_defaultTarget->getArea());
        area.setSize(sz);
        d_defaultTarget->setArea(area);
    }
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::enableExtraStateSettings(bool setting)
{
    d_initExtraStates = setting;
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::grabTextures()
{
    // perform grab operations for texture targets
    TextureTargetList::iterator target_iterator = d_textureTargets.begin();
    for (; target_iterator != d_textureTargets.end(); ++target_iterator)
        static_cast<OpenGLTextureTarget*>(*target_iterator)->grabTexture();

    // perform grab on regular textures
    TextureMap::iterator texture_iterator = d_textures.begin();
    for (; texture_iterator != d_textures.end(); ++texture_iterator)
        texture_iterator->second->grabTexture();
}

//----------------------------------------------------------------------------//
void OpenGLRendererBase::restoreTextures()
{
    // perform restore on textures
    TextureMap::iterator texture_iterator = d_textures.begin();
    for (; texture_iterator != d_textures.end(); ++texture_iterator)
        texture_iterator->second->restoreTexture();

    // perform restore operations for texture targets
    TextureTargetList::iterator target_iterator = d_textureTargets.begin();
    for (; target_iterator != d_textureTargets.end(); ++target_iterator)
        static_cast<OpenGLTextureTarget*>(*target_iterator)->restoreTexture();
}

//----------------------------------------------------------------------------//
float OpenGLRendererBase::getNextPOTSize(const float f)
{
    uint size = static_cast<uint>(f);

    // if not power of 2
    if ((size & (size - 1)) || !size)
    {
        int log = 0;

        // get integer log of 'size' to base 2
        while (size >>= 1)
            ++log;

        // use log to calculate value to use as size.
        size = (2 << log);
    }

    return static_cast<float>(size);
}

//----------------------------------------------------------------------------//
const CEGUI::Rectf& OpenGLRendererBase::getActiveViewPort()
{
    return d_activeRenderTarget->getArea();
}

//----------------------------------------------------------------------------//
bool OpenGLRendererBase::isTexCoordSystemFlipped() const
{
    return true;
}

//----------------------------------------------------------------------------//

}

