#pragma once
#include <string>

class ParserException : public std::exception {
private:
    std::string message;
public:
    explicit ParserException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};