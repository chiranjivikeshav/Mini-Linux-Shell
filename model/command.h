#ifndef COMMAND_H
#define COMMAND_H

#include<vector>
#include<string>
#include<redirection.h>

struct Command
{
    std::string name;
    std::vector<std::string> args;
    std::vector<Redirection>redirections;
};

#endif