#ifndef COMMAND_H
#define COMMAND_H

#include "ASTNode.h"

#include<vector>
#include<string>
#include "redirection.h"

struct Command : ASTNode
{
    std::string name;
    std::vector<std::string> args;
    std::vector<Redirection>redirections;

    Command(){
        type = NodeType::COMMAND;
    }
};

#endif