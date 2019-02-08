#include "arg_parser.h"

namespace ymir::utils
{

namespace
{

enum class TypeArg
{
    Key,
    Value,
    Error
};

TypeArg classify(const std::string_view param) {
    switch (param.size()) {
        case 0:
            return TypeArg::Error;
        case 1:
        case 2:
            return param.find('-') == std::string::npos ? TypeArg::Value : TypeArg::Error;
        default:
            return param.substr(0, 2) == "--" ?  TypeArg::Key : TypeArg::Value;
    }
}

} // namespace

ArgParser::ArgParser(const int argc, char** argv)
    : argc_(argc)
    , argv_(argv) {
    if (argv == nullptr) {
        throw std::runtime_error("Invalid argv list");
    }
    if (argc < 1) {
        throw std::runtime_error("Unexpected args count = " + std::to_string(argc));
    }
}

ArgParser& ArgParser::addParam(const std::string& name,
                               const std::string& desc,
                               const bool has_value) {
    paramToAttr_[name] = {desc, has_value};
    return *this;
}

void ArgParser::help(const std::string_view helpHeader, std::ostream& stream) const {
    stream << helpHeader << "\n";
    stream << "OPTIONS:" << "\n";
    for (const auto& [name, attr] : paramToAttr_) {
        stream << "  " << name << " - " << attr.desc << "\n";
    }
}

bool ArgParser::has(const std::string_view name) const {
    return paramToVal_.find(name) != paramToVal_.end();
}

std::string_view ArgParser::get(const std::string_view name) const {
    return paramToVal_.find(name)->second;
}

void ArgParser::parse() {
    using namespace std::string_literals;
    auto nextArg =
        [this, current{argv_ + 1}](std::string_view& arg) mutable -> bool { // First arg is programm name
            if (current == argv_ + argc_) {
                return false;
            }
            arg = *current++;
            return true;
        };

    std::string_view arg;
    while (nextArg(arg)) {
        if (classify(arg) == TypeArg::Key) {
            const auto found = paramToAttr_.find(arg);
            if (found != paramToAttr_.end()) {
                std::string_view val;
                if (found->second.has_value) {
                    if (!nextArg(val) || classify(val) != TypeArg::Value) {
                        throw std::runtime_error("Expected val for parameter "s + arg.data());
                    }
                }
                paramToVal_.emplace(found->first, val);
            }
        }
        else {
            throw std::runtime_error("Unexpected parameter "s + arg.data());
        }
    }
}

} // namespace ymir::utils
