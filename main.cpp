#include <iostream>
#include "Lexer.hpp"
#include "LexerException.hpp"
#include "Token.hpp"
#include "Parser.hpp"

int main() {
    try {
        Lexer lexer("  \\ x. x ");
        std::vector<Token> tokens = lexer.tokenize();
        Parser parser(tokens);
        AST ast = parser.parse();

    } catch (const LexerException& e) {
        std::cerr << "Lexer error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Parsing completed successfully." << std::endl;

    return 0;
}