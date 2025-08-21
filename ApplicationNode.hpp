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
};