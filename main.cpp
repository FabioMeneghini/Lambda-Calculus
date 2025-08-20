#include <iostream>
#include "Lexer.hpp"
#include "LexerException.hpp"
#include "Token.hpp"

int main() {
    try {
        Lexer lexer("  \\ x.var x ");
        lexer.expect(Token::Type::Lambda);
        lexer.expect(Token::Type::Var);
        lexer.expect(Token::Type::Dot);
        lexer.expect(Token::Type::Var);
        lexer.expect(Token::Type::Var);
        lexer.expectEof();
        std::cout << "Lexer test passed." << std::endl;
    } catch (const LexerException& e) {
        std::cerr << "Lexer error: " << e.what() << std::endl;
    }

    return 0;
}