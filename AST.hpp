#pragma once
#include "ExpNode.hpp"

class AST {
private:
    ExpNode* root;
public:
    AST(ExpNode*);

    ~AST();

    //eval
};
