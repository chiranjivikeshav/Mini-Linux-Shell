#ifndef PARSER_H
#define PARSER_H

#include "command.h"
#include "redirection.h"
#include <string>

class Parser
{
public:
    Command parse(const std::string& input);
private:
    void getRedirection(const std::string& arg, Redirection& rd);
};

#endif