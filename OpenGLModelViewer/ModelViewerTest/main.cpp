#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Dank memes.\n";

    int result = Catch::Session().run( argc, argv );
    return ( result < 0xff ? result : 0xff );
}
