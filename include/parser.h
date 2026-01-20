#ifndef PARSER_H
#define PARSER_H

#include "command.h"
#include <string>

class Parser
{
    public:
    Command parse(const std::string& input);
};

#endif