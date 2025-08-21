#include "AST.hpp"
#include "ExpNode.hpp"

AST::AST(ExpNode* root) : root(root) {}

AST::~AST() {
    delete root;
}