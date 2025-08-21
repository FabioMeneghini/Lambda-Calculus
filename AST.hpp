#pragma once
#include "ExpNode.hpp"

class AST {
private:
    ExpNode* root;
public:
    AST(ExpNode* = nullptr);

    ~AST();

    AST eval() const; // Evaluate the AST
};
