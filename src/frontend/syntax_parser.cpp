#include <iostream>
#include "syntax_parser.h"

namespace ymir
{

ASTP SyntaxParser::parse(ILexer& lexer) {
    while (true) {
        const auto [token, tokenVal] = lexer.lex();
        if (token == Token::Eof)
            break;
        if (token == Token::Number)
            return make<ASTNumber>(std::get<int>(*tokenVal));
    }
    return nullptr;
}


} // namespace ymir
