#pragma once
#include <memory>

namespace ymir
{

class IAST
{
public:
    virtual ~IAST() = default;
};

using ASTP = std::shared_ptr<IAST>;


class ASTNumber : public IAST {
public:
    ASTNumber(int val) : val_(val) {}
    int val() const { return val_; }
private:
    int val_;
};

template<typename T, typename... Args>
std::shared_ptr<T> make(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

} // namespace
