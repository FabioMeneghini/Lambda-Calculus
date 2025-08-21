#pragma once
#include "ExpNode.hpp"
#include "VarNode.hpp"

class AbstractionNode : public ExpNode {
private:
    VarNode* var;
    ExpNode* body;
public:
    AbstractionNode(VarNode*, ExpNode*);
    virtual ~AbstractionNode();

    ExpNode* clone() const override;
    virtual ExpNode* substitute(const std::string& var, ExpNode* value) const override; // Substitute variable with value
    ExpNode* eval() override; // Evaluate the abstraction node

    VarNode* getVar() const;
    ExpNode* getBody() const;

    std::string toString() const override; // Convert the abstraction node to a string representation
};