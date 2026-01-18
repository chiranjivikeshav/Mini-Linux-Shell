#include "shell.h"
#include "executer.h"

#include<iostream>
#include<string>

void Shell::printPrompt()
{
    std::cout<<"$ ";
    std::cout.flush();
}

void Shell::run()
{
    std::string command;
    Executer executer;
    while (true)
    {
        printPrompt();

        if (!std::getline(std::cin, command))
        {
            break;
        }

        if (command.empty())
        {
            continue;
        }

        if (command == "exit")
        {
            return;
        }

        executer.execute(command);
    }
}
