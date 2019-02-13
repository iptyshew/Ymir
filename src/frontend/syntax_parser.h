#pragma once
#include "../ast/ast.h"
#include "lexer.h"

namespace ymir
{

class SyntaxParser
{
public:
    SyntaxParser(Lexer& lexer);
    ASTP parse();
private:
    Lexer& lexer_;
};

} // namespace ymir
