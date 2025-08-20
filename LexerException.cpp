#include "LexerException.hpp"

LexerException::LexerException(const std::string& message)
    : message(message) {}

const char* LexerException::what() const noexcept {
    return message.c_str();
}