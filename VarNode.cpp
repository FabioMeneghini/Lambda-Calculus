#include "VarNode.hpp"
#include "Token.hpp"
#include "ExpNode.hpp"

VarNode::VarNode(const std::string& name)
    : name(name) {}

ExpNode* VarNode::clone() const {
    return new VarNode(name);
}

ExpNode* VarNode::eval() {
    return this->clone(); // Variables evaluate to themselves
}

const std::string& VarNode::getName() const {
    return name;
}

ExpNode* VarNode::substitute(const std::string& var, ExpNode* value) const {
    if (name == var) {
        return value->clone(); // Ensure you have a clone method in ExpNode
    }
    return new VarNode(name); // Return a new VarNode if no substitution is made
}

std::string VarNode::toString() const {
    return name; // Return the variable name as its string representation
}