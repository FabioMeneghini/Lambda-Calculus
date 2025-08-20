#pragma once
#include <string>
#include <vector>
#include "Token.hpp"
#include "LexerException.hpp"

class Lexer {
private:
    std::string input;
    unsigned long position;

    Token nextToken();
    void skipWhitespace();
    char currentChar() const;
    void advance();
public:
    Lexer(const std::string& input);

    std::vector<Token> tokenize();

    void expect(char c);
    void expect(Token::Type expectedType);
    void expectEof();
};