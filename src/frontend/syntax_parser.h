#pragma once
#include "../ast/ast.h"
#include "ilexer.h"

namespace ymir
{

class SyntaxParser
{
public:
    SyntaxParser(ILexer& lexer);
    ASTP parse();
private:
    ILexer& lexer_;
};

} // namespace ymir
