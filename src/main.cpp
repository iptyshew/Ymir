#include <iostream>
#include <vector>
#include "frontend/frontend.h"
#include "utils/arg_parser.h"
#include "utils/ast_print.h"

int main(int argc, const char** argv) {
    ymir::utils::ArgParser argParser(argc, argv);
    argParser
        .addParam("--file", "Path to file with source code", true)
        .addParam("--help", "Print help");
    try {
        argParser.parse();
        if (argParser.has("--help")) {
            const auto header = "Overview : Ymir C compiler";
            argParser.help(header, std::cout);
            return 0;
        }
        if (!argParser.has("--file")) {
            std::cout << "--file option is required\n";
            return 0;
        }

        ymir::Frontend frontend;
        auto ast = frontend.compile(*argParser.get("--file"));
        ymir::utils::ASTPrinter printer(std::cout);
        ast->accept(printer);

        return 0;
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        argParser.help("You can use:", std::cout);
        return 1;
    }
}
