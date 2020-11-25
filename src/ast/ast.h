#pragma once
#include <memory>
#include <variant>

namespace ymir
{

class IVisitor;

class IAST
{
public:
    virtual ~IAST() = default;
    virtual void accept(IVisitor& visitor) const = 0;
};

using ASTP = std::shared_ptr<IAST>;

class ASTLiteral : public IAST
{
public:
    ASTLiteral(int value) : value_(value) {}
    void accept(IVisitor& visitor) const override;
    int value() const { return value_; }
private:
    int value_;
};

enum class BinaryOperator
{
    Addition,
    Subtraction,
    Multiplication,
    Division
};

class ASTBinaryOperation : public IAST
{
public:
    ASTBinaryOperation(BinaryOperator op, ASTP lhs, ASTP rhs)
        : op_(op)
        , lhs_(lhs)
        , rhs_(rhs) {}

    void accept(IVisitor& visitor) const override;

    BinaryOperator oper() const { return op_; }
    const IAST& lhs() const { return *lhs_; }
    const IAST& rhs() const { return *rhs_; }

private:
    BinaryOperator op_;
    ASTP lhs_;
    ASTP rhs_;
};

} // namespace
