#include <iostream>
#include <vector>
#include "arg_parser.h"

int main(int argc, char** argv) {
    Ymir::utils::ArgParser argParser(argc, argv);
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
        std::cout << argParser.get("--file") << std::endl;
        return 0;
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        argParser.help("You can use:", std::cout);
        return 1;
    }
}
