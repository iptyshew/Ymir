#include <gtest/gtest.h>
#include "../src/utils/arg_parser.h"

using namespace ymir::utils;
using namespace std::string_literals;


TEST(ArgParserTest, GetParam) {
    const char* params[] = {"ymir", "--file", "name", "--help"};
    ArgParser parser(std::size(params), params);

    parser.addParam(params[1], "", true);
    parser.addParam(params[3], "", false);
    parser.parse();

    ASSERT_TRUE(parser.has(params[1]));
    const auto param = parser.get(params[1]);
    ASSERT_TRUE(param);
    ASSERT_EQ(*param, params[2]);
    ASSERT_TRUE(parser.has(params[3]));
}

TEST(ArgParserTest, SkipExpectedVal) {
    const char* params[] = {"ymir", "--file", "--name"};
    ArgParser parser(std::size(params), params);
    parser.addParam(params[1], "", true);
    try {
        parser.parse();
        ASSERT_TRUE(false);
    }
    catch (const std::exception& error) {
        ASSERT_TRUE(true);
    }
}

TEST(ArgParserTest, ArgWithoutVal) {
    const char* params[] = {"ymir", "--help"};
    ArgParser parser(std::size(params), params);

    parser.addParam(params[1], "");
    parser.parse();

    ASSERT_TRUE(parser.has(params[1]));
    ASSERT_FALSE(parser.get(params[1]));
}

TEST(ArgParserTest, SomeParams) {
    const char* params[] = {"ymir", "--name", "name", "--help", "--file", "name"};

    ArgParser parser(std::size(params), params);
    parser.addParam(params[1], "", true);
    parser.addParam(params[3], "", false);
    parser.addParam(params[4], "", true);
    parser.parse();

    ASSERT_TRUE(parser.has(params[1]));
    ASSERT_TRUE(parser.has(params[3]));
    ASSERT_TRUE(parser.has(params[4]));
}
