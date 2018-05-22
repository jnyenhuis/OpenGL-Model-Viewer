#include "catch.hpp"

#include <string>
#include <iostream>
#include "fileio.h"

TEST_CASE("Read All File Text")
{
    SECTION("File Doesn't Exist") {
        std::string text = OpenGlModelViewer::readAllText("DNE.txt");
        REQUIRE(text == "");
    }

    SECTION("Simple Shader File") {
        std::string text = OpenGlModelViewer::readAllText(".\\data\\test.frag");
        REQUIRE(!text.empty());
    }
}
