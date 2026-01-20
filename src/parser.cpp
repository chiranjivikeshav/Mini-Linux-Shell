#include "parser.h"
#include <sstream>

Command Parser::parse(const std::string& input)
{
    std::istringstream iss(input);
    Command cmd;
    iss >> cmd.name;

    cmd.args.push_back(cmd.name);

    std:: string arg;
    while (iss >> arg)
    {
        cmd.args.push_back(arg);
    }
    return cmd;
}