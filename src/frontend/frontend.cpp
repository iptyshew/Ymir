#include "lexer.h"
#include "syntax_parser.h"
#include "frontend.h"

namespace ymir
{

ASTP Frontend::compile(const std::string_view path)
{
    const Source source(path);
    Lexer lexer(source);
    SyntaxParser parser;
    return parser.parse(lexer);
}

} // namespace ymir
