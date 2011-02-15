// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "EventIterator.pypp.hpp"

namespace bp = boost::python;

void Iterator_next(::CEGUI::ConstBaseIterator<std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >& t)
{
    t++;
}

void Iterator_previous(::CEGUI::ConstBaseIterator<std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >& t)
{
    t--;
}

void register_EventIterator_class(){

    { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >
        typedef bp::class_< CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > > EventIterator_exposer_t;
        EventIterator_exposer_t EventIterator_exposer = EventIterator_exposer_t( "EventIterator", bp::no_init );
        bp::scope EventIterator_scope( EventIterator_exposer );
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::getCurrentKey
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef ::CEGUI::String ( exported_class_t::*getCurrentKey_function_type )(  ) const;
            
            EventIterator_exposer.def( 
                "getCurrentKey"
                , getCurrentKey_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::getCurrentKey )
                , "*!\n\
            \n\
               Return the key for the item at the current iterator position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::getCurrentValue
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef ::CEGUI::Event * ( exported_class_t::*getCurrentValue_function_type )(  ) const;
            
            EventIterator_exposer.def( 
                "getCurrentValue"
                , getCurrentValue_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::getCurrentValue )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
            \n\
               Return the value for the item at the current iterator position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::isAtEnd
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef bool ( exported_class_t::*isAtEnd_function_type )(  ) const;
            
            EventIterator_exposer.def( 
                "isAtEnd"
                , isAtEnd_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::isAtEnd )
                , "*!\n\
            \n\
               Return whether the current iterator position is at the end of the iterators range.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::isAtStart
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef bool ( exported_class_t::*isAtStart_function_type )(  ) const;
            
            EventIterator_exposer.def( 
                "isAtStart"
                , isAtStart_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::isAtStart )
                , "*!\n\
            \n\
               Return whether the current iterator position is at the start of the iterators range.\n\
            *\n" );
        
        }
        EventIterator_exposer.def( bp::self != bp::self );
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::operator=
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef ::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > & ( exported_class_t::*assign_function_type )( ::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > const & ) ;
            
            EventIterator_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >()
                , "*!\n\
            \n\
               ConstBaseIterator assignment operator\n\
            *\n" );
        
        }
        EventIterator_exposer.def( bp::self == bp::self );
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::toEnd
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef void ( exported_class_t::*toEnd_function_type )(  ) ;
            
            EventIterator_exposer.def( 
                "toEnd"
                , toEnd_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::toEnd )
                , "*!\n\
            \n\
               Set the iterator current position to the end position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::toStart
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > > exported_class_t;
            typedef void ( exported_class_t::*toStart_function_type )(  ) ;
            
            EventIterator_exposer.def( 
                "toStart"
                , toStart_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::Event*, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::Event*> > > >::toStart )
                , "*!\n\
            \n\
               Set the iterator current position to the start position.\n\
            *\n" );
        
        }
        EventIterator_exposer.def("next", &::Iterator_next);
        EventIterator_exposer.def("previous", &::Iterator_previous);
    }

}
