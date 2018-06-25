//
// Created by goforbroke on 25.06.18.
//

#ifndef MATHEMATICS_STDAFX_H
#define MATHEMATICS_STDAFX_H

#include <string>
#include <vector>

using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T *) {
    return std::is_base_of<Base, T>::value;
}

class Execution {
public:
    virtual string exec(vector<string> params) = 0;
};

class Operation : public Execution {
private:
    string sign;
public:
    Operation(const string &sign) : sign(sign) {}
};

class Func : public Execution {
private:
    string name;
public:
    Func(const string &name) : name(name) {}
};

class Expression {
private:
    Execution *execution; // func or operation
    vector<string> parameters;
public:
    Expression(Execution *execution, const vector<string> &parameters) : execution(execution), parameters(parameters) {
        if (instanceof<Operation>(execution) && parameters.size() > 2) {
            throw "More than 2 params for operation";
        }
    }

    string exec() {
        return this->execution->exec(this->parameters);
    }
};

#endif //MATHEMATICS_STDAFX_H
