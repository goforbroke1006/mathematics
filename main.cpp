#include <iostream>
#include "Parser.h"

int main() {
    std::cout << "Your expression: ";

    std::string expression;
    std::cin >> expression;

    std::cout << (new Parser())->parse(expression)->getResult() << std::endl;

    return 0;
}