#pragma once
#include "ilexer.h"
#include "source.h"

namespace ymir
{

class Lexer : public ILexer
{
public:
    Lexer(const Source& source);
    std::pair<Token, std::optional<TokenVal>> lex() override;

private:
    const Source& source_;
    const Symbol* const begin_;
    const Symbol* const end_;
    const Symbol* head_;
};

} // namespace ymir
