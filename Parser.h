//
// Created by goforbroke on 11.12.17.
//

#ifndef MATHEMATICS_PARSER_H
#define MATHEMATICS_PARSER_H

#include <cmath>

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

unsigned int getPriority(std::string operation) {
    if (operation == "+" || operation == "-") return 1;
    if (operation == "*" || operation == "/") return 2;
    if (operation == "^") return 3;
}

class Parser {
private:
    std::string expression;
    unsigned int position;

    double getNextDouble() {
        std::string result;
        std::string l;
        while (position < this->expression.length()) {
            l = this->expression.substr(position, 1);
            if (l == " ") {
                position++;
                continue;
            }
            if (is_number(l) || l == "." || ("-" == l && result.empty())) {
                result += l;
            } else break;
            position++;
        }
        l.erase();
//        std::cout << "found token: " << result << std::endl;
        return result.length() > 0 ? std::stod(result.c_str()) : 0.0;
    }

    std::string getNextOperation() {
        std::string result;
        std::string l;
        while (position < this->expression.length()) {
            l = this->expression.substr(position, 1);
            if (l == " ") {
                position++;
                continue;
            }
            if (l == "+" || l == "-" || l == "*" || l == "/" || l == "^") {
                result += l;
                position++;
                break;
            }
            position++;
        }
//        std::cout << "found operator: " << result << std::endl;
        return result;
    }

    bool canReadNext(std::string str) {
        int locPos = this->position;
        while (this->expression.substr(this->position, 1) == " ") this->position++;
        if (this->expression.substr(this->position, str.length()) == str) {
            this->position++;
            return true;
        }
        this->position = locPos;
        return false;
    }

public:
    Parser(std::string expr) : expression(expr), position(0) {}

    ~Parser() {
        expression.clear();
        expression.shrink_to_fit();
    }

    double calc() {
        double first = this->getNextDouble();
        std::string operation = this->getNextOperation();
        if (operation == "") return first;

        canReadNext("(");
        double second = this->calc();
        canReadNext(")");
        second += this->calc();

        std::cout << first << " " << operation << " " << second << std::endl;

        if (operation == ";") return 0.0;
        else if (operation == "+") return first + second;
        else if (operation == "-") return first - second;
        else if (operation == "*") return first * second;
        else if (operation == "/") return first / second;
        else if (operation == "^") return std::pow(first, second);
        else {
            std::cerr << "Unexpected operator \"" << operation << "\"" << std::endl;
        }


//        if ()
//            this->position++;

        return 0.0;
    }
};


#endif //MATHEMATICS_PARSER_H
