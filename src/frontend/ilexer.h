#pragma once
#include <variant>
#include <optional>

namespace ymir
{

enum class Token
{
    Number,
    String,
    Eof
};

using TokenVal = std::variant<int, std::string>;

class ILexer
{
public:
    virtual std::pair<Token, std::optional<TokenVal>> lex() = 0;
};

} // namespace ymir
