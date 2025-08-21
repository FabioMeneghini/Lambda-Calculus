#include "AbstractionNode.hpp"
#include "VarNode.hpp"
#include "ExpNode.hpp"

AbstractionNode::AbstractionNode(VarNode* var, ExpNode* body)
    : var(var), body(body) {}

AbstractionNode::~AbstractionNode() {
    delete var;
    delete body;
}

ExpNode* AbstractionNode::clone() const {
    return new AbstractionNode(static_cast<VarNode*>(var->clone()), body->clone());
}

ExpNode* AbstractionNode::substitute(const std::string& varName, ExpNode* value) const {
    // If the variable to substitute is the same as the abstraction's variable, do not substitute in the body
    if (var->getName() == varName) {
        return this->clone(); // Return a clone of the abstraction without substitution
    }
    return new AbstractionNode(static_cast<VarNode*>(var->clone()), body->substitute(varName, value));
}

ExpNode* AbstractionNode::eval() {
    return this->clone(); // Abstraction nodes evaluate to themselves
}

VarNode* AbstractionNode::getVar() const {
    return var;
}

ExpNode* AbstractionNode::getBody() const {
    return body;
}

std::string AbstractionNode::toString() const {
    return "\\" + var->getName() + ". " + body->toString();
}