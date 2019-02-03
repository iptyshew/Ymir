#pragma once
#include <string>
#include <map>
#include <ostream>

namespace Ymir::utils
{

class ArgParser
{
public:
    ArgParser(const int argc, char** argv);

    //\todo Auto add prefix  −−
    ArgParser& addParam(const std::string& name,
                        const std::string& desc,
                        const bool has_value = false);

    void help(const std::string_view helpHeader, std::ostream& stream) const;

    void parse();

    bool has(const std::string_view name) const;
    std::string_view get(const std::string_view name) const;

private:
    struct ParamAttr
    {
        std::string desc;
        bool has_value;
    };

private:
    const int argc_;
    char** argv_;
    std::map<std::string, ParamAttr, std::less<>> paramToAttr_;
    std::map<std::string_view, std::string_view> paramToVal_;
};

} // namespace Ymir
