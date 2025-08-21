#include "ApplicationNode.hpp"
#include "ExpNode.hpp"
#include "VarNode.hpp"
#include "AbstractionNode.hpp"

ApplicationNode::ApplicationNode(ExpNode* lexp, ExpNode* rexp)
    : lexp(lexp), rexp(rexp) {}

ApplicationNode::~ApplicationNode() {
    delete lexp;
    delete rexp;
}

ExpNode* ApplicationNode::clone() const {
    return new ApplicationNode(lexp->clone(), rexp->clone());
}

ExpNode* ApplicationNode::substitute(const std::string& var, ExpNode* value) const {
    return new ApplicationNode(
        lexp->substitute(var, value),
        rexp->substitute(var, value)
    );
}

ExpNode* ApplicationNode::eval() {
    ExpNode* leftEval = lexp->eval();
    ExpNode* rightEval = rexp->eval();
    if (dynamic_cast<AbstractionNode*>(leftEval)) { //REDEX
        // If the left expression is an abstraction, apply it to the right expression
        AbstractionNode* absNode = static_cast<AbstractionNode*>(leftEval);
        ExpNode* substituted = absNode->substitute(absNode->getVar()->getName(), rightEval); // first evaluates the right expression, then substitutes
        ExpNode* result = substituted->eval(); // Evaluate the result of the substitution
        return result; // Return the evaluated result
    }
    return new ApplicationNode(leftEval, rightEval); // If not an abstraction, return a new application node with evaluated expressions
}