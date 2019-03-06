#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "syntax_parser.h"

using namespace ymir;
using namespace testing;

class LexerMock : public ILexer {
public:
    MOCK_METHOD0(lex, std::pair<Token, std::optional<TokenVal>>());
};

class SyntaxParserTest : public Test
                       , public SyntaxParser {
public:
    LexerMock lexer_;
};

TEST_F(SyntaxParserTest, Basic) {
    const int value = 10;
    EXPECT_CALL(lexer_, lex()).WillOnce(Return(std::make_pair(Token::Number, value)));
    ASTP ast = parse(lexer_);
    const auto number = std::dynamic_pointer_cast<ASTNumber>(ast);
    EXPECT_TRUE(number != nullptr);

    EXPECT_EQ(number->val(), value);
}
