//
// Created by goforbroke on 11.12.17.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Parser.h"

TEST_CASE("Factorials of 1 and higher are computed (pass)", "[single-file]") {
//    REQUIRE((new Parser("2 + 3"))->calc() == 5.0);
//    REQUIRE((new Parser("5 + 4 * 6"))->calc() == 29.0);
//    REQUIRE((new Parser("7 + 2^3"))->calc() == 15.0);

    REQUIRE((new Parser("(2 + 3) ^ 5 - 7 * 3 + 4 * 5 + 2 + (1 + 1) ^ 2"))->calc() == 3130.0);
    REQUIRE((new Parser("- 7 * 3 + (2 + 3) ^ 5 + 4 * 5 + 2 + (1 + 1) ^ 2"))->calc() == 3130.0);
    REQUIRE((new Parser("- 7 * 3 + 4 * 5 + 2 + (1 + 1) ^ 2 + (2 + 3) ^ 5"))->calc() == 3130.0);

//    REQUIRE((new Parser("10 + (4 + 2)^3"))->calc() == 226.0);
//    REQUIRE((new Parser("10 + 4 + 2^3"))->calc() == 22.0);
//    REQUIRE((new Parser("10 + 2^3 + 4"))->calc() == 22.0);
//    REQUIRE((new Parser)->exec("var n = 6; n + 3") == "9");
//    REQUIRE((new Parser)->exec("var n = 6; n - 1") == "5");
//    REQUIRE((new Parser)->exec("var n = 8; n * 2") == "16");
//    REQUIRE((new Parser)->exec("var n = 90; n / 2") == "45");
}