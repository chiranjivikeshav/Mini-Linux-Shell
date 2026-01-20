#include "shell.h"
#include "parser.h"
#include "executor.h"

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
    Parser parser;
    Executor executor;
    while (true)
    {
        printPrompt();

        if (!std::getline(std::cin, command))
        {
            break;
        }else if (command.empty())
        {
            continue;
        }

        Command cmd = parser.parse(command);
        executor.execute(cmd);
    }
}
