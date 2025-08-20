#include "Token.hpp"
#include <utility>
#include <string>
#include <iostream>

Token::Token(const Token::Type type, const std::string& value)
    : type(type), value(std::move(value)) {}

Token::Type Token::getType() const {
    return type;
}

const std::string& Token::getValue() const {
    return value;
}