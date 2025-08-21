#include "AST.hpp"
#include "ExpNode.hpp"
#include <iostream>

AST::AST(ExpNode* root) : root(root) {}

AST::~AST() {
    delete root;
}

AST AST::eval() const {
    if (root) {
        ExpNode* evaluatedRoot = root->eval();
        return AST(evaluatedRoot);
    }
    return AST(nullptr); // Return an empty AST if root is null
}

std::string AST::print() const {
    if (root) {
        return root->toString();
    }
    return "Empty AST"; // Return a message for an empty AST
}