#pragma once
#include <map>
#include "ilexer.h"
#include "source.h"

namespace ymir
{

using CharTokens = std::map<char, Token>;
using StringTokens = std::map<std::string, Token>;

class Lexer : public ILexer
{
public:
    Lexer(const Source& source);
    std::pair<Token, std::optional<TokenVal>> lex() override;

private:
    static const CharTokens char_tokens;
    static const StringTokens keyword_tokens;
    const Symbol* const begin_;
    const Symbol* const end_;
    const Symbol* head_;
};

} // namespace ymir
