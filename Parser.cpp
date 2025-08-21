#include "Parser.hpp"
#include "AST.hpp"
#include "Lexer.hpp"
#include "ParserException.hpp"
#include "ExpNode.hpp"
#include "VarNode.hpp"
#include "AbstractionNode.hpp"
#include "ApplicationNode.hpp"
#include <vector>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

ExpNode* Parser::parseVariable() {
    if (tokens.empty() || tokens.front().getType() != Token::Type::Var) {
        throw ParserException("Expected variable token");
    }
    Token token = tokens.front();
    tokens.erase(tokens.begin()); // Consume the token
    return new VarNode(token.getValue());
}

ExpNode* Parser::parseAbstraction() {
    if (tokens.empty() || tokens.front().getType() != Token::Type::Lambda) {
        throw ParserException("Expected lambda token");
    }
    tokens.erase(tokens.begin()); // Consume the lambda token
    if (tokens.empty() || tokens.front().getType() != Token::Type::Var) {
        throw ParserException("Expected variable after lambda");
    }
    std::string varName = tokens.front().getValue();
    tokens.erase(tokens.begin()); // Consume the variable token
    if (tokens.empty() || tokens.front().getType() != Token::Type::Dot) {
        throw ParserException("Expected dot after variable in abstraction");
    }
    tokens.erase(tokens.begin()); // Consume the dot token
    ExpNode* body = parseExpression(); // Parse the body of the abstraction
    return new AbstractionNode(new VarNode(varName), body);
}

ExpNode* Parser::parseApplication() {
    if (tokens.empty() || tokens.front().getType() != Token::Type::LPar) {
        throw ParserException("Expected left parenthesis for application");
    }
    tokens.erase(tokens.begin()); // Consume the left parenthesis
    ExpNode* lexp = parseExpression(); // Parse the left expression
    ExpNode* rexp = parseExpression(); // Parse the right expression
    if (tokens.empty() || tokens.front().getType() != Token::Type::RPar) {
        throw ParserException("Expected right parenthesis for application");
    }
    tokens.erase(tokens.begin()); // Consume the right parenthesis
    return new ApplicationNode(lexp, rexp); // Placeholder for application node
}

ExpNode* Parser::parseExpression() {
    if (tokens.empty()) {
        throw ParserException("No tokens to parse");
    }
    const Token& token = tokens.front();
    switch (token.getType()) {
        case Token::Type::Var:
            return parseVariable();
        case Token::Type::Lambda:
            return parseAbstraction();
        case Token::Type::LPar:
            return parseApplication();
        default:
            throw ParserException("Unexpected token type: " + std::to_string(static_cast<int>(token.getType())));
    }
}

AST Parser::parse() {
    ExpNode* root = parseExpression();
    return AST(root);
}