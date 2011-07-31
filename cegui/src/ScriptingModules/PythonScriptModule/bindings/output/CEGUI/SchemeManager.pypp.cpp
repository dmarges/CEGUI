// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "SchemeManager.pypp.hpp"

namespace bp = boost::python;

struct SchemeManager_wrapper : CEGUI::SchemeManager, bp::wrapper< CEGUI::SchemeManager > {

    SchemeManager_wrapper( )
    : CEGUI::SchemeManager( )
      , bp::wrapper< CEGUI::SchemeManager >(){
        // null constructor
    
    }

    virtual void doPostObjectAdditionAction( ::CEGUI::Scheme & object ){
        if( bp::override func_doPostObjectAdditionAction = this->get_override( "doPostObjectAdditionAction" ) )
            func_doPostObjectAdditionAction( boost::ref(object) );
        else{
            this->CEGUI::SchemeManager::doPostObjectAdditionAction( boost::ref(object) );
        }
    }
    
    virtual void default_doPostObjectAdditionAction( ::CEGUI::Scheme & object ){
        CEGUI::SchemeManager::doPostObjectAdditionAction( boost::ref(object) );
    }

    ::CEGUI::Scheme & doExistingObjectAction( ::CEGUI::String const object_name, ::CEGUI::Scheme * object, ::CEGUI::XMLResourceExistsAction const action ){
        return CEGUI::NamedXMLResourceManager< CEGUI::Scheme, CEGUI::Scheme_xmlHandler >::doExistingObjectAction( object_name, boost::python::ptr(object), action );
    }

    virtual void fireEvent( ::CEGUI::String const & name, ::CEGUI::EventArgs & args, ::CEGUI::String const & eventNamespace="" ) {
        if( bp::override func_fireEvent = this->get_override( "fireEvent" ) )
            func_fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
        else{
            this->CEGUI::EventSet::fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
        }
    }
    
    void default_fireEvent( ::CEGUI::String const & name, ::CEGUI::EventArgs & args, ::CEGUI::String const & eventNamespace="" ) {
        CEGUI::EventSet::fireEvent( boost::ref(name), boost::ref(args), boost::ref(eventNamespace) );
    }

    void fireEvent_impl( ::CEGUI::String const & name, ::CEGUI::EventArgs & args ){
        CEGUI::EventSet::fireEvent_impl( boost::ref(name), boost::ref(args) );
    }

    ::CEGUI::ScriptModule * getScriptModule(  ) const {
        return CEGUI::EventSet::getScriptModule(  );
    }

    virtual ::CEGUI::RefCounted< CEGUI::BoundSlot > subscribeScriptedEvent( ::CEGUI::String const & name, ::CEGUI::String const & subscriber_name ) {
        if( bp::override func_subscribeScriptedEvent = this->get_override( "subscribeScriptedEvent" ) )
            return func_subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
        else{
            return this->CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
        }
    }
    
    ::CEGUI::RefCounted< CEGUI::BoundSlot > default_subscribeScriptedEvent( ::CEGUI::String const & name, ::CEGUI::String const & subscriber_name ) {
        return CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), boost::ref(subscriber_name) );
    }

    virtual ::CEGUI::RefCounted< CEGUI::BoundSlot > subscribeScriptedEvent( ::CEGUI::String const & name, unsigned int group, ::CEGUI::String const & subscriber_name ) {
        if( bp::override func_subscribeScriptedEvent = this->get_override( "subscribeScriptedEvent" ) )
            return func_subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
        else{
            return this->CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
        }
    }
    
    ::CEGUI::RefCounted< CEGUI::BoundSlot > default_subscribeScriptedEvent( ::CEGUI::String const & name, unsigned int group, ::CEGUI::String const & subscriber_name ) {
        return CEGUI::EventSet::subscribeScriptedEvent( boost::ref(name), group, boost::ref(subscriber_name) );
    }

};

void register_SchemeManager_class(){

    { //::CEGUI::SchemeManager
        typedef bp::class_< SchemeManager_wrapper, bp::bases< CEGUI::Singleton< CEGUI::SchemeManager >, CEGUI::NamedXMLResourceManager< CEGUI::Scheme, CEGUI::Scheme_xmlHandler > >, boost::noncopyable > SchemeManager_exposer_t;
        SchemeManager_exposer_t SchemeManager_exposer = SchemeManager_exposer_t( "SchemeManager", bp::init< >("! Constructor.\n") );
        bp::scope SchemeManager_scope( SchemeManager_exposer );
        { //::CEGUI::SchemeManager::doPostObjectAdditionAction
        
            typedef void ( SchemeManager_wrapper::*doPostObjectAdditionAction_function_type )( ::CEGUI::Scheme & ) ;
            
            SchemeManager_exposer.def( 
                "doPostObjectAdditionAction"
                , doPostObjectAdditionAction_function_type( &SchemeManager_wrapper::default_doPostObjectAdditionAction )
                , ( bp::arg("object") )
                , "override from base\n" );
        
        }
        { //::CEGUI::SchemeManager::getIterator
        
            typedef ::CEGUI::ConstMapIterator< std::map<CEGUI::String, CEGUI::Scheme*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Scheme*> > > > ( ::CEGUI::SchemeManager::*getIterator_function_type )(  ) const;
            
            SchemeManager_exposer.def( 
                "getIterator"
                , getIterator_function_type( &::CEGUI::SchemeManager::getIterator )
                , "*!\n\
            \n\
                Return a SchemeManager.SchemeIterator object to iterate over the\n\
                available schemes.\n\
            *\n" );
        
        }
        { //::CEGUI::NamedXMLResourceManager< CEGUI::Scheme, CEGUI::Scheme_xmlHandler >::doExistingObjectAction
        
            typedef CEGUI::SchemeManager exported_class_t;
            typedef ::CEGUI::Scheme & ( SchemeManager_wrapper::*doExistingObjectAction_function_type )( ::CEGUI::String const,::CEGUI::Scheme *,::CEGUI::XMLResourceExistsAction const ) ;
            
            SchemeManager_exposer.def( 
                "doExistingObjectAction"
                , doExistingObjectAction_function_type( &SchemeManager_wrapper::doExistingObjectAction )
                , ( bp::arg("object_name"), bp::arg("object"), bp::arg("action") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::CEGUI::EventSet::fireEvent
        
            typedef void ( ::CEGUI::EventSet::*fireEvent_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs &,::CEGUI::String const & ) ;
            typedef void ( SchemeManager_wrapper::*default_fireEvent_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs &,::CEGUI::String const & ) ;
            
            SchemeManager_exposer.def( 
                "fireEvent"
                , fireEvent_function_type(&::CEGUI::EventSet::fireEvent)
                , default_fireEvent_function_type(&SchemeManager_wrapper::default_fireEvent)
                , ( bp::arg("name"), bp::arg("args"), bp::arg("eventNamespace")="" ) );
        
        }
        { //::CEGUI::EventSet::fireEvent_impl
        
            typedef void ( SchemeManager_wrapper::*fireEvent_impl_function_type )( ::CEGUI::String const &,::CEGUI::EventArgs & ) ;
            
            SchemeManager_exposer.def( 
                "fireEvent_impl"
                , fireEvent_impl_function_type( &SchemeManager_wrapper::fireEvent_impl )
                , ( bp::arg("name"), bp::arg("args") )
                , "! Implementation event firing member\n" );
        
        }
        { //::CEGUI::EventSet::getScriptModule
        
            typedef ::CEGUI::ScriptModule * ( SchemeManager_wrapper::*getScriptModule_function_type )(  ) const;
            
            SchemeManager_exposer.def( 
                "getScriptModule"
                , getScriptModule_function_type( &SchemeManager_wrapper::getScriptModule )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "! Implementation event firing member\n\
            ! Helper to return the script module pointer or throw.\n" );
        
        }
        { //::CEGUI::EventSet::subscribeScriptedEvent
        
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ::CEGUI::EventSet::*subscribeScriptedEvent_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( SchemeManager_wrapper::*default_subscribeScriptedEvent_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            
            SchemeManager_exposer.def( 
                "subscribeScriptedEvent"
                , subscribeScriptedEvent_function_type(&::CEGUI::EventSet::subscribeScriptedEvent)
                , default_subscribeScriptedEvent_function_type(&SchemeManager_wrapper::default_subscribeScriptedEvent)
                , ( bp::arg("name"), bp::arg("subscriber_name") ) );
        
        }
        { //::CEGUI::EventSet::subscribeScriptedEvent
        
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( ::CEGUI::EventSet::*subscribeScriptedEvent_function_type )( ::CEGUI::String const &,unsigned int,::CEGUI::String const & ) ;
            typedef ::CEGUI::RefCounted< CEGUI::BoundSlot > ( SchemeManager_wrapper::*default_subscribeScriptedEvent_function_type )( ::CEGUI::String const &,unsigned int,::CEGUI::String const & ) ;
            
            SchemeManager_exposer.def( 
                "subscribeScriptedEvent"
                , subscribeScriptedEvent_function_type(&::CEGUI::EventSet::subscribeScriptedEvent)
                , default_subscribeScriptedEvent_function_type(&SchemeManager_wrapper::default_subscribeScriptedEvent)
                , ( bp::arg("name"), bp::arg("group"), bp::arg("subscriber_name") ) );
        
        }
    }

}
