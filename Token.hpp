#pragma once
#include <string>

class Token {
public:
    enum class Type {
        Var,
        Lambda,
        Dot,
        LPar,
        RPar,
        Eof
    };
private:
    Type type;
    std::string value;
public:
    Token(const Type type, const std::string& value = "");

    Type getType() const;

    const std::string& getValue() const;
};