#include <iostream>
#include "Lexer.hpp"
#include "LexerException.hpp"
#include "Token.hpp"
#include "Parser.hpp"

const std::string ZERO  = "\\f.\\x.x";
const std::string ONE   = "\\f.\\x.(f x)";
const std::string TWO   = "\\f.\\x.(f (f x))";
const std::string THREE = "\\f.\\x.(f (f (f x)))";
const std::string SUM   = "\\a.\\b.\\f.\\x.((a f) ((b f) x))";
const std::string SUCC  = "\\m.\\g.\\y.(g ((m g) y))";

int main() {
    std::string program = "((" + SUM + " " + THREE + ") " + "(" + SUCC + " " + TWO + "))";
    Lexer lexer(program);
    std::vector<Token> tokens = lexer.tokenize();
    Parser parser(tokens);
    AST ast = parser.parse();
    std::cout << "PROG: " << ast.print();
    AST evaluatedAst = ast.eval();
    std::cout << "\nEVAL: " << evaluatedAst.print();

    return 0;
}