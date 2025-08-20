#pragma once
#include <string>

class LexerException : public std::exception {
private:
    std::string message;
public:
    explicit LexerException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};