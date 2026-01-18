#include "executer.h"

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

void Executer::execute(const std::string& command)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return;
    }

    if (pid == 0)
    {
        char* args[] = {
            const_cast<char*>(command.c_str()),
            nullptr
        };

        execvp(args[0], args);

        perror("execution failed");
        _exit(1);
    } else
    {
        waitpid(pid, nullptr, 0);
    }
}
