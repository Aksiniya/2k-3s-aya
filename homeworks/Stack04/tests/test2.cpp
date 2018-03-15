#include "catch.hpp"
#include <stack.hpp>


//when you add elements in stack more than it can contain
SCENARIO( "stack can be resized (in biger size) by adding elements", "[stack]" ){
    GIVEN( "a stack with some items" ){
        
        Stack<char> sc( 2 );
        
        REQUIRE( sc.count() == 0 );
        REQUIRE( sc.empty() == true );
        
        WHEN( "you add two elements" ){
            sc.push('a');
            sc.push('b');
            THEN( "the count() and empty() changed" ){
                REQUIRE( sc.count() == 2 );
                REQUIRE( sc.empty() == false );
            }
        }
    }
    
}