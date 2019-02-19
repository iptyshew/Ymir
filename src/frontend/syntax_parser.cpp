#include <iostream>
#include "syntax_parser.h"

namespace ymir
{

SyntaxParser::SyntaxParser(ILexer& lexer)
    : lexer_(lexer) {

}

ASTP SyntaxParser::parse() {
    while (true) {
        const auto [token, tokenVal] = lexer_.lex();
        if (token == Token::Eof)
            break;
        if (token == Token::Number)
            std::cout << "Number " << (std::get<int>(*tokenVal)) << std::endl;
    }
    return nullptr;
}


} // namespace ymir
