#include "Lexer.hpp"
#include "LexerException.hpp"

Lexer::Lexer(const std::string& input)
    : input(input), position(0) {}

void Lexer::skipWhitespace() {
    while (position < input.size() && std::isspace(currentChar())) {
        advance();
    }
}

char Lexer::currentChar() const {
    if (position >= input.size()) {
        throw LexerException("Unexpected end of input");
    }
    return input[position];
}

void Lexer::advance() {
    if (position < input.size()) {
        position++;
    }
}

void Lexer::expect(char c) {
    skipWhitespace();
    if (currentChar() != c) {
        throw LexerException("Expected '" + std::string(1, c) + "', found '" + currentChar() + "'");
    }
    advance();
}

void Lexer::expect(Token::Type expectedType) {
    Token token = nextToken();
    if (token.getType() != expectedType) {
        throw LexerException("Expected token type " + std::to_string(static_cast<int>(expectedType)) +
                             ", found " + std::to_string(static_cast<int>(token.getType())));
    }
}

void Lexer::expectEof() {
    skipWhitespace();
    if (position < input.size()) {
        throw LexerException("Expected end of input, found '" + std::string(1, currentChar()) + "'");
    }
}

Token Lexer::nextToken() {
    skipWhitespace();

    if (position >= input.size()) {
        return Token(Token::Type::Eof);
    }

    char current = currentChar();

    if (std::isalpha(current)) {
        std::string value;
        while (position < input.size() && std::isalpha(currentChar())) {
            value += currentChar();
            advance();
        }
        return Token(Token::Type::Var, value);
    }

    if (current == '\\') { // aggiungere che si possa scrivere anche 'lam'
        advance();
        return Token(Token::Type::Lambda);
    }

    if (current == '.') {
        advance();
        return Token(Token::Type::Dot);
    }

    if (current == '(') {
        advance();
        return Token(Token::Type::LPar);
    }

    if (current == ')') {
        advance();
        return Token(Token::Type::RPar);
    }

    throw LexerException("Unexpected character: " + std::string(1, current));
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (true) {
        Token token = nextToken();
        if (token.getType() == Token::Type::Eof) {
            break;
        }
        tokens.push_back(token);
    }
    return tokens;
}