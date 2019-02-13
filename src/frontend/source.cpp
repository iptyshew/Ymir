#include <fstream>
#include <algorithm>
#include <iterator>
#include "source.h"

namespace ymir
{

using namespace std::string_literals;

Source::Source(const std::string_view path) {
    std::ifstream stream(path.data());
    if (!stream)
        throw std::runtime_error("Can't open file "s + path.data());

    std::transform(  // \todo calc size of file for reserve source_
            std::istreambuf_iterator<char>(stream),
            std::istreambuf_iterator<char>(),
            std::back_inserter(source_),
            [](char c){ return static_cast<Symbol>(c);});
}

const Symbol* Source::begin() const
{
    return source_.data();
}

const Symbol* Source::end() const
{
    return source_.data() + source_.size();
}

} // namespace ymir
