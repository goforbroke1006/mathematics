//
// Created by goforbroke on 18.12.17.
//

#ifndef MATHEMATICS_NODE_H
#define MATHEMATICS_NODE_H

class Node {
private:
    std::string op;
    Node *leftNode;
    Node *rightNode;
    double number;
public:
    Node(double n) {
        this->number = n;
    }

    Node(Node *l, std::string op, Node *r) {
        this->leftNode = l;
        this->op = op;
        this->rightNode = r;
    }

    Node(double l, std::string op, double r) {
        this->leftNode = new Node(l);
        this->op = op;
        this->rightNode = new Node(r);
    }

    Node(Node *l, std::string op, double r) {
        this->leftNode = l;
        this->op = op;
        this->rightNode = new Node(r);
    }

    Node(double l, std::string op, Node *r) {
        this->leftNode = new Node(l);
        this->op = op;
        this->rightNode = r;
    }

    bool isLeaf() {
        return this->number != NULL
               && this->leftNode == NULL
               && this->rightNode == NULL;
    }

    double getResult() {
        if (this->isLeaf())
            return this->number;

        if (this->op == "+") {
            std::cout << this->leftNode->getResult() << " + " << this->rightNode->getResult() << std::endl;
            return this->leftNode->getResult() + this->rightNode->getResult();
        }
        if (this->op == "-") {
            std::cout << this->leftNode->getResult() << " - " << this->rightNode->getResult() << std::endl;
            return this->leftNode->getResult() - this->rightNode->getResult();
        }
        if (this->op == "*") {
            std::cout << this->leftNode->getResult() << " * " << this->rightNode->getResult() << std::endl;
            return this->leftNode->getResult() * this->rightNode->getResult();
        }
        if (this->op == "/") {
            std::cout << this->leftNode->getResult() << " / " << this->rightNode->getResult() << std::endl;
            return this->leftNode->getResult() / this->rightNode->getResult();
        }
        if (this->op == "^") {
            std::cout << this->leftNode->getResult() << " ^ " << this->rightNode->getResult() << std::endl;
            return std::pow(this->leftNode->getResult(), this->rightNode->getResult());
        }
    }
};

#endif //MATHEMATICS_NODE_H
