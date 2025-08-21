#pragma once
#include <string>
#include "ExpNode.hpp"
#include "Token.hpp"

class VarNode : public ExpNode {
private:
    std::string name;
public:
    VarNode(const std::string& name);
    virtual ~VarNode() = default;
};