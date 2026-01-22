#include "parser.h"
#include <sstream>
#include <iostream>

Command Parser::parse(const std::string& input)
{
    std::istringstream iss(input);
    Command cmd;
    iss >> cmd.name;

    cmd.args.push_back(cmd.name);

    std:: string arg;
    while (iss >> arg)
    {
        if (arg == ">") {
            if (!(iss >> cmd.outputFile)) {
                std::cerr << "syntax error: expected file after >\n";
                break;
            }
            cmd.append = false;
        }
        else if (arg == ">>") {
            if (!(iss >> cmd.outputFile)) {
                std::cerr << "syntax error: expected file after >>\n";
                break;
            }
            cmd.append = true;
        }
        else if (arg == "<") {
            if (!(iss >> cmd.inputFile)) {
                std::cerr << "syntax error: expected file after <\n";
                break;
            }
        }
        else {
            cmd.args.push_back(arg);
        }
    }
    return cmd;
}