#include "executor.h"

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <string>

void Executor::execute(const Command& cmd)
{
    if (cmd.name == "exit")
    {
        exit(0);
    }else if (cmd.name == "cd")
    {
        handleCD(cmd);
        return;
    }

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

void Executor::handleCD(const Command& cmd)
{
    std::string targetDir;
    if (cmd.args.size() == 1 || cmd.args[1] == "~")
    {
        targetDir = getenv("HOME");
    }else
    {
        targetDir = cmd.args[1];
    }
    if (chdir(targetDir.c_str()) < 0)
    {
        perror("command failed");
    }
}