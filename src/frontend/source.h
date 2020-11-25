#pragma once
#include <string>
#include <vector>
#include "types.h"

namespace ymir
{

class Source
{
public:
    explicit Source(const std::string_view path);
    Source(const char* begin, const char* end);
    const Symbol* begin() const;
    const Symbol* end() const;

private:
    std::vector<Symbol> source_;
};

} // namespace ymir
