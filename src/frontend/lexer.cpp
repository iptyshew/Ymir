#include <stdexcept>
#include "lexer.h"

namespace ymir
{

namespace {

int makeInteger(const Symbol*, const Symbol*) {
    return 10;
}

}

Lexer::Lexer(const Source& source)
    : source_(source)
    , begin_(source.begin())
    , end_(source.end())
    , head_(source.begin()) {
}

std::pair<Token, std::optional<TokenVal>> Lexer::lex() {
    std::optional<TokenVal> tokenVal;
    auto tokBegin = head_;
    while (head_ != end_) {
        if (std::isdigit(*head_)) {
            ++head_;
        } else {
            throw std::runtime_error("Unexpected symbol");
        }
    }
    if (tokBegin != head_)
        tokenVal = makeInteger(tokBegin, head_);

    if (tokenVal)
        return {Token::Number, tokenVal};
    return {Token::Eof, tokenVal};
}

} // namespace ymir
