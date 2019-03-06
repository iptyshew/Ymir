#pragma once
#include "../ast/ast.h"
#include "ilexer.h"

namespace ymir
{

class SyntaxParser
{
public:
    ASTP parse(ILexer& lexer);
};

} // namespace ymir
