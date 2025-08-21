#include "ApplicationNode.hpp"
#include "ExpNode.hpp"
#include "VarNode.hpp"

ApplicationNode::ApplicationNode(ExpNode* lexp, ExpNode* rexp)
    : lexp(lexp), rexp(rexp) {}

ApplicationNode::~ApplicationNode() {
    delete lexp;
    delete rexp;
}