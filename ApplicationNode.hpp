#pragma once
#include "ExpNode.hpp"
#include "VarNode.hpp"

class ApplicationNode : public ExpNode {
private:
    ExpNode* lexp;
    ExpNode* rexp;
public:
    ApplicationNode(ExpNode*, ExpNode*);
    virtual ~ApplicationNode();

    ExpNode* eval() override; // Evaluate the application node
    ExpNode* substitute(const std::string& var, ExpNode* value) const override; // Substitute variable with value
    ExpNode* clone() const override; // Clone the application node

    std::string toString() const override; // Convert the application node to a string representation
};