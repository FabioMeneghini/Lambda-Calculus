#pragma once
#include "ExpNode.hpp"
#include <string>

class AST {
private:
    ExpNode* root;
public:
    AST(ExpNode* = nullptr);
    ~AST();

    AST eval() const; // Evaluate the AST
    std::string print() const;
};
