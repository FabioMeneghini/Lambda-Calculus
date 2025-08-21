#include "AbstractionNode.hpp"
#include "VarNode.hpp"
#include "ExpNode.hpp"

AbstractionNode::AbstractionNode(VarNode* var, ExpNode* body)
    : var(var), body(body) {}

AbstractionNode::~AbstractionNode() {
    delete var;
    delete body;
}