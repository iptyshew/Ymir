#pragma once
#include <variant>
#include <optional>

namespace ymir
{

enum class Token
{
    OpenParenthesis,  // (
    CloseParenthesis, // )
    Comma,            // ,
    Semicolon,        // ;
    Plus,             // +
    Minus,            // -
    Star,             // *
    Slash,            // /
    Assignment,       // =

    Int,
    Number,
    Identifier,
    Eof
};

using TokenVal = std::variant<int, std::string>;

class ILexer
{
public:
    virtual ~ILexer() = default;
    virtual std::pair<Token, std::optional<TokenVal>> lex() = 0;
};

} // namespace ymir
