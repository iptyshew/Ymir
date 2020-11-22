#include <stdexcept>
#include "lexer.h"

namespace ymir
{

const CharTokens Lexer::char_tokens = {
    {'(', Token::OpenParenthesis},
    {')', Token::CloseParenthesis},
    {',', Token::Comma},
    {';', Token::Semicolon},
    {'+', Token::Plus},
    {'-', Token::Minus},
    {'*', Token::Star},
    {'/', Token::Slash},
    {'=', Token::Assignment}
};

const StringTokens Lexer::keyword_tokens = {
    {"int", Token::Int}
};

Lexer::Lexer(const Source& source)
    : source_(source)
    , begin_(source.begin())
    , end_(source.end())
    , head_(source.begin()) {
}

std::pair<Token, std::optional<TokenVal>> Lexer::lex() {
    while (head_ != end_ && (*head_ == ' ' || *head_ == '\n')) {
        ++head_;
    }

    std::optional<TokenVal> tokenVal;
    bool first_symbol_is_digit = false;
    auto tokBegin = head_;

    while (head_ != end_) {
        if (*head_ == ' ' || *head_ == '\n') {
            break;
        }
        else if (std::isdigit(*head_)) {
            first_symbol_is_digit |= (tokBegin == head_);
            ++head_;
        }
        else if ((std::isalpha(*head_) || *head_ == '_') && !first_symbol_is_digit) {
            ++head_;
        } else {
            const auto it = char_tokens.find(*head_);
            if (it != char_tokens.end()) {
                if (tokBegin == head_) {
                    ++head_;
                    return {it->second, tokenVal};
                }
                break;
            }
            throw std::runtime_error("Unexpected symbol");
        }
    }

    if (tokBegin == head_) {
        return {Token::Eof, tokenVal};
    }

    const std::string token_val {tokBegin, head_};
    if (first_symbol_is_digit) {
        tokenVal = std::stoi(token_val);
        return {Token::Number, tokenVal};
    }

    const auto it = keyword_tokens.find(token_val);
    if (it != keyword_tokens.end()) {
        return {it->second, token_val};
    }

    return {Token::Identifier, token_val};
}

} // namespace ymir
