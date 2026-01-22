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
        if (arg == ">" || arg == ">>" || arg == "<" || arg == "2>") {
            std::string tempFile;
            if (!(iss >> tempFile)) {
                std::cerr << "syntax error: expected file after " << arg << "\n";
                break;
            }
            Redirection rd;
            setRedirectionType(arg, rd);
            rd.file = tempFile;
            cmd.redirections.push_back(rd);
        }
        else {
            cmd.args.push_back(arg);
        }
    }
    return cmd;
}

void Parser::setRedirectionType(const std::string& arg, Redirection& rd)
{
    if (arg == ">") {
        rd.type = RedirectType::OUTPUT;
    }
    else if (arg == ">>") {
        rd.type = RedirectType::APPEND;
    }
    else if (arg == "<") {
        rd.type = RedirectType::INPUT;
    }
    else if (arg == "2>") {
        rd.type = RedirectType::STDERR;
    }
}