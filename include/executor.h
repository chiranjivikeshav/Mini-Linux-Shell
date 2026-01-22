#ifndef EXECUTER_H
#define EXECUTER_H

#include "command.h"

class Executor
{
public:
    void execute(const Command& cmd);

private:
    void handleCD(const Command& cmd);
    void handleRedirection(const Command& cmd);
};

#endif