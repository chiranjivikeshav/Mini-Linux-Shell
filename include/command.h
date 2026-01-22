#ifndef COMMAND_H
#define COMMAND_H

#include<vector>
#include<string>

struct Command
{
    std::string name;
    std::vector<std::string> args;

    std::string inputFile; // for <
    std::string outputFile; // for >
    bool append = false; // for >>
};

#endif