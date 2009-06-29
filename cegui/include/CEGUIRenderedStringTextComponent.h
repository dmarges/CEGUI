/***********************************************************************
    filename:   CEGUIRenderedStringTextComponent.h
    created:    25/05/2009
    author:     Paul Turner
 *************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2009 Paul D Turner & The CEGUI Development Team
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
#ifndef _CEGUIRenderedStringTextComponent_h_
#define _CEGUIRenderedStringTextComponent_h_

#include "CEGUIRenderedStringComponent.h"
#include "CEGUIColourRect.h"
#include "CEGUIString.h"

// Start of CEGUI namespace section
namespace CEGUI
{
class Font;

//! String component that draws an image.
class CEGUIEXPORT RenderedStringTextComponent : public RenderedStringComponent
{
public:
    //! Constructor
    RenderedStringTextComponent();
    RenderedStringTextComponent(const String& text);
    RenderedStringTextComponent(const String& text, const String& font_name);
    RenderedStringTextComponent(const String& text, Font* font);

    //! Set the text to be rendered by this component.
    void setText(const String& text);
    //! return the text that will be rendered by this component
    const String& getText() const;
    //! set the font to use when rendering the text.
    void setFont(Font* font);
    //! set the font to use when rendering the text.
    void setFont(const String& font_name);
    //! return the font set to be used.  If 0 the default font will be used.
    Font* getFont() const;
    //! Set the colour values used when rendering this component.
    void setColours(const ColourRect& cr);
    //! Set the colour values used when rendering this component.
    void setColours(const colour& c);
    //! return the ColourRect object used when drawing this component.
    const ColourRect& getColours() const;

    // implementation of abstract base interface
    void draw(GeometryBuffer& buffer, const Vector2& position,
              const ColourRect* mod_colours, const Rect* clip_rect,
              const float vertical_space) const;
    Size getPixelSize() const;
    bool canSplit() const;
    RenderedStringTextComponent* split(float split_point, bool first_component);
    RenderedStringTextComponent* clone() const;

protected:
    static size_t getNextTokenLength(const String& text, size_t start_idx);

    //! pointer to the image drawn by the component.
    String d_text;
    //! Font to use for text rendering, 0 for system default.
    Font* d_font;
    //! ColourRect object describing the colours to use when rendering.
    ColourRect d_colours;
};
    
} // End of  CEGUI namespace section

#endif // end of guard _CEGUIRenderedStringTextComponent_h_
