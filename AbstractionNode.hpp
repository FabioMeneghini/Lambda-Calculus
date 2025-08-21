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
};