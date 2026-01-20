#include "executor.h"

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>

void Executor::execute(const Command& cmd)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return;
    }

    if (pid == 0)
    {
        std::vector<char*> argv;
        for (const auto& arg : cmd.args)
            argv.push_back(const_cast<char*>(arg.c_str()));
        argv.push_back(nullptr);

        execvp(cmd.name.c_str(), argv.data());

        perror("execution failed");
        _exit(1);
    }
    waitpid(pid, nullptr, 0);
}
