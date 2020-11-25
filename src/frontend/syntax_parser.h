#pragma once
#include "../ast/ast.h"
#include "ilexer.h"
#include <map>
#include <optional>

namespace ymir
{

class SyntaxParser
{
public:
    SyntaxParser(ILexer& lexer);
    ASTP parse();

private:
    ASTP parseNumberExpr();
    ASTP parseParenExpr();
    ASTP parsePrimary();
    ASTP parseBinOpRHS(int prec, ASTP lhs);
    ASTP parseExpr();

private:
    void nextToken();
    int getPrecedence(Token tok) const;

private:
    ILexer& lexer_;
    Token curTok_;
    std::optional<TokenVal> curTokVal_;

    std::map<Token, int> precedence_;
};

} // namespace ymir
