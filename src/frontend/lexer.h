#pragma once
#include <variant>
#include <optional>
#include "source.h"

namespace ymir
{

enum class Token
{
    Number,
    String,
    Eof
};

using TokenVal = std::variant<int, std::string>;

class Lexer
{
public:
    Lexer(const Source& source);
    std::pair<Token, std::optional<TokenVal>> lex();

private:
    const Source& source_;
    const Symbol* const begin_;
    const Symbol* const end_;
    const Symbol* head_;
};

} // namespace ymir
