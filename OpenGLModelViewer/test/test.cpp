#include "catch.hpp"

TEST_CASE("Test Case")
{
    int a = 0;
    int b = 1;
    b -= 1;
    REQUIRE(a == b);
}
