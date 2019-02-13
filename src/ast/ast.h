#pragma once
#include <memory>

namespace ymir
{

class IAST
{
    virtual ~IAST() = default;
};

using ASTP = std::shared_ptr<IAST>;

} // namespace
