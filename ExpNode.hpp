#pragma once
#include <string>

class ExpNode {
public:
    virtual ~ExpNode() = default;
    virtual ExpNode* eval() = 0; // Evaluate the expression node
    virtual ExpNode* substitute(const std::string& var, ExpNode* value) const = 0; // Substitute variable with value

    virtual ExpNode* clone() const = 0; // Clone the expression node
    
    virtual std::string toString() const = 0; // Convert the expression node to a string representation
};