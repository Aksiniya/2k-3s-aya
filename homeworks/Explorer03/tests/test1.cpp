// without of "#define CATCH_CONFIG_MAIN" because it in main.cpp
#include "catch.hpp"
#include <explorer.hpp>

TEST_CASE("when you try to write info about files", "[explorer]" ){
    
   writeInfo("/Users/macbook/Desktop/CmakeEx2Test.txt", "/Users/macbook/Desktop/");
    
   REQUIRE( bf::exists("/Users/macbook/Desktop/info_CmakeEx2Test.txt") == true );

}