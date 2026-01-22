#ifndef EXECUTER_H
#define EXECUTER_H

#include "command.h"
#include "redirection.h"

class Executor
{
public:
    void execute(const Command& cmd);

private:
    void handleCD(const Command& cmd);
    void handleRedirection(const std::vector<Redirection>& rds);
    void redirect(int targetFd, const std::string& file, int flags);
};

#endif