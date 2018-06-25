#include <iostream>
#include <vector>
#include "Parser.h"



int main() {
//    std::cout << "Your expression: ";
//
//    std::string expression;
//    std::cin >> expression;
//
//    std::cout << (new Parser(expression))->calc() << std::endl;


    /*Node *n0 = new Node(2.0, "+", 3.0);
    Node *n1 = new Node(n0, "^", 5.0);
    Node *n2 = new Node(n1, "-", new Node(7.0, "*", 3.0));
    Node *n3 = new Node(n2, "+", new Node(4.0, "*", 5.0));
    Node *n4 = new Node(n3, "+", 2.0);
    Node *nn0 = new Node(1.0, "+", 1.0);
    Node *nn1 = new Node(nn0, "^", 2.0);
    Node *root = new Node(n4, "+", nn1);

    std::cout << root->getResult();*/

    Node *n0 = new Node(2.0, "+", 3.0);
    Node *n1 = new Node(3.0, "+", 2.0);

//    Node *n0 = new Node(2.0);
//    Node *n1 = new Node(2.0);

    std::cout << (*n0 == *n1) << std::endl;
    std::cout << (2.0 == 2.0) << std::endl;

    return 0;
}