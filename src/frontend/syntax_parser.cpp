#include <iostream>
#include <memory>
#include <stdexcept>
#include "syntax_parser.h"

namespace ymir
{

SyntaxParser::SyntaxParser(ILexer& lexer)
    : lexer_(lexer) {
    precedence_[Token::Plus] = 10;
    precedence_[Token::Minus] = 20;
    precedence_[Token::Star] = 30;
    precedence_[Token::Slash] = 40;
}

ASTP SyntaxParser::parse() {
    return parseExpr();
}

static BinaryOperator toBinOp(Token tok) {
    switch (tok) {
        case Token::Plus: return BinaryOperator::Addition;
        case Token::Minus: return BinaryOperator::Subtraction;
        case Token::Star: return BinaryOperator::Multiplication;
        case Token::Slash: return BinaryOperator::Division;
        default: {
            throw std::runtime_error("Unexpected binary operator");
        }
    }
}

ASTP SyntaxParser::parseNumberExpr() {
    ASTP result = std::make_shared<ASTLiteral>(std::get<int>(*curTokVal_));
    nextToken();
    return result;
}

ASTP SyntaxParser::parseParenExpr() {
    nextToken();
    ASTP v = parseExpr();
    if (!v)
        return nullptr;

    if (curTok_ != Token::CloseParenthesis)
        throw std::runtime_error("expected ')'");
    nextToken();
    return v;
}

ASTP SyntaxParser::parsePrimary() {
    switch (curTok_) {
        case Token::Number:
            return parseNumberExpr();
        case Token::OpenParenthesis:
            return parseParenExpr();
        default:
            throw std::runtime_error("unknown token when expecting an expression");
    }
}

ASTP SyntaxParser::parseBinOpRHS(int prec, ASTP lhs) {
    while (true) {
        int tokPrec = getPrecedence(curTok_);

        if (tokPrec < prec)
            return lhs;

        Token BinOp = curTok_;
        nextToken();

        ASTP rhs = parsePrimary();
        if (!rhs)
            return nullptr;

        int nextPrec = getPrecedence(curTok_);
        if (tokPrec < nextPrec) {
            rhs = parseBinOpRHS(tokPrec + 1, rhs);
            if (!rhs)
                return nullptr;
        }

        lhs = std::make_shared<ASTBinaryOperation>(toBinOp(BinOp), lhs, rhs);
    }
}

ASTP SyntaxParser::parseExpr() {
    ASTP lhs = parsePrimary();
    if (!lhs)
        return nullptr;

    return parseBinOpRHS(0, lhs);
}

void SyntaxParser::nextToken() {
    std::tie(curTok_, curTokVal_) = lexer_.lex();
}

int SyntaxParser::getPrecedence(Token tok) const {
    auto found = precedence_.find(tok);
    if (found != precedence_.end()) {
        return found->second;
    }
    return 0;
}

} // namespace ymir
