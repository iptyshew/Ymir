#include "ast.h"
#include "visitor.h"

namespace ymir
{

void ASTLiteral::accept(IVisitor& visitor) const {
    visitor.visit(*this);
}

void ASTBinaryOperation::accept(IVisitor& visitor) const {
    visitor.visit(*this);
}

}
