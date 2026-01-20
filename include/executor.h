#ifndef EXECUTER_H
#define EXECUTER_H

#include "command.h"

class Executor
{
    public:
    void execute(const Command& cmd);
};

#endif