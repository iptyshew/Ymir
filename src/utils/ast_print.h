#pragma once
#include "../ast/visitor.h"
#include <ostream>
#include <string_view>

namespace ymir::utils
{

std::string_view binOpToString(BinaryOperator op) {
    switch (op) {
        case BinaryOperator::Addition: return "+";
        case BinaryOperator::Subtraction: return "-";
        case BinaryOperator::Multiplication: return "*";
        case BinaryOperator::Division: return "//";
    }
}

class ASTPrinter : public IVisitor
{
public:
    ASTPrinter(std::ostream& stream)
        : stream_(stream) {}

    void visit(const ASTLiteral& literal) override {
        stream_ << literal.value();
    }

    void visit(const ASTBinaryOperation& binaryOperation) override {
        binaryOperation.lhs().accept(*this);

    }
private:
    std::ostream& stream_;
};

}
