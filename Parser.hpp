#pragma once
#include "AST.hpp"
#include "Lexer.hpp"

class Parser {
private:
    std::vector<Token> tokens;
    ExpNode* parseExpression();
    ExpNode* parseAbstraction();
    ExpNode* parseApplication();
    ExpNode* parseVariable();
public:
    Parser(const std::vector<Token>&);

    AST parse();
};