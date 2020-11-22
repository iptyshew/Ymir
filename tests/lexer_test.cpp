#include <gtest/gtest.h>
#include "../src/frontend/source.h"
#include "../src/frontend/lexer.h"

using namespace ymir;

TEST(LexerTest,  Number) {
    const char parsed [] = "123";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
}

TEST(LexerTest,  Identifier) {
    const char parsed [] = "abc";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Identifier);
}

TEST(LexerTest,  Identifier2) {
    const char parsed [] = "a12_3c";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Identifier);
}

TEST(LexerTest,  Int) {
    const char parsed [] = "int";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Int);
}

TEST(LexerTest,  OpenParenthesis) {
    const char parsed [] = "(";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::OpenParenthesis);
}

TEST(LexerTest,  CloseParenthesis) {
    const char parsed [] = ")";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::CloseParenthesis);
}

TEST(LexerTest,  Comma) {
    const char parsed [] = ",";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Comma);
}

TEST(LexerTest,  Semicolon) {
    const char parsed [] = ";";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Semicolon);
}

TEST(LexerTest,  Plus) {
    const char parsed [] = "+";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Plus);
}

TEST(LexerTest,  Minus) {
    const char parsed [] = "-";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Minus);
}

TEST(LexerTest,  Star) {
    const char parsed [] = "*";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Star);
}

TEST(LexerTest,  Slash) {
    const char parsed [] = "/";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Slash);
}

TEST(LexerTest,  Assignment) {
    const char parsed [] = "=";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Assignment);
}

TEST(LexerTest,  Eof) {
    const char parsed [] = "";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    const std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Eof);
}

TEST(LexerTest,  ComplexTest) {
    const char parsed [] = " \n int a_ = \n 7 * 3 - 4, a1 = (3 / 3) + 2;";
    Source source(std::cbegin(parsed), std::prev(std::cend(parsed)));
    Lexer lexer(source);
    std::pair<Token, std::optional<TokenVal>> token = lexer.lex();
    ASSERT_EQ(token.first, Token::Int);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Identifier);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Assignment);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Star);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Minus);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Comma);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Identifier);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Assignment);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::OpenParenthesis);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Slash);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::CloseParenthesis);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Plus);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Number);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Semicolon);
    token = lexer.lex();
    ASSERT_EQ(token.first, Token::Eof);
}
