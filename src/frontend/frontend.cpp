#include "lexer.h"
#include "syntax_parser.h"
#include <string_view>
#include "frontend.h"

namespace ymir
{

ASTP Frontend::compile(const std::string_view path)
{
    const Source source(path);
    Lexer lexer(source);
    SyntaxParser parser(lexer);
    return parser.parse();
}

} // namespace ymir
