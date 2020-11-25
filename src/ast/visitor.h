#pragma once
#include "ast.h"

namespace ymir
{

class IVisitor
{
public:
    virtual ~IVisitor() = default;
    virtual void visit(const ASTLiteral&) = 0;
    virtual void visit(const ASTBinaryOperation&) = 0;
};

}
