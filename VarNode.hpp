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

    virtual ExpNode* eval() override; // Evaluate the variable node

    const std::string& getName() const;

    ExpNode* clone() const override;
    virtual ExpNode* substitute(const std::string& var, ExpNode* value) const override; // Substitute variable with value
};