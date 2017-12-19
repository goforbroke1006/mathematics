//
// Created by goforbroke on 11.12.17.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Parser.h"

//TEST_CASE("Nodes should be comparable") {
//    Node *n10 = new Node(2.0, "+", 3.0);
//    Node *n20 = new Node(3.0, "+", 2.0);
//    REQUIRE((*n10 == *n20) == true);
//
//    Node *n11 = new Node(n10, "^", 5.0);
//    Node *n21 = new Node(n20, "^", 5.0);
//    REQUIRE((*n11 == *n21) == true);
//
//    Node *n12 = new Node(n11, "-", new Node(7.0, "*", 3.0));
//    Node *n22 = new Node(n21, "-", new Node(7.0, "*", 3.0));
//    REQUIRE((*n12 == *n22) == true);
//}

TEST_CASE("Parser::getNextToken should correct return tokens of other type") {
    std::string expr = "(22 + 376) ^ 58 - 7 * 3";
    Parser *parser = new Parser(expr);

    REQUIRE(parser->getNextToken() == "(");
    REQUIRE(parser->getNextToken() == "22");
    REQUIRE(parser->getNextToken() == "+");
    REQUIRE(parser->getNextToken() == "376");
    REQUIRE(parser->getNextToken() == ")");
    REQUIRE(parser->getNextToken() == "^");
    REQUIRE(parser->getNextToken() == "58");
    REQUIRE(parser->getNextToken() == "-");
    REQUIRE(parser->getNextToken() == "7");
    REQUIRE(parser->getNextToken() == "*");
    REQUIRE(parser->getNextToken() == "3");
    REQUIRE(parser->getNextToken().empty());
    REQUIRE(parser->getNextToken().empty());
}

//TEST_CASE("Parser should translate string to node bunch") {
//    Node *n0 = new Node(2.0, "+", 3.0);
//    Node *n1 = new Node(n0, "^", 5.0);
//    Node *n2 = new Node(n1, "-", new Node(7.0, "*", 3.0));
//    Node *n3 = new Node(n2, "+", new Node(4.0, "*", 5.0));
//    Node *n4 = new Node(n3, "+", 2.0);
//    Node *nn0 = new Node(1.0, "+", 1.0);
//    Node *nn1 = new Node(nn0, "^", 2.0);
//    Node *root = new Node(n4, "+", nn1);
//    std::string expr1 = "(2 + 3) ^ 5 - 7 * 3 + 4 * 5 + 2 + (1 + 1) ^ 2";
//    Node *actual = (new Parser(expr1))->parse();
//    REQUIRE((*actual == *root) == true);
//}
