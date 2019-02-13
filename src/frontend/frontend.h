#pragma once
#include <string>
#include "../ast/ast.h"

namespace ymir
{

class Frontend
{
public:
    ASTP compile(const std::string_view path);
};

} // namespace ymir
