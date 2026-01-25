#include "shell.h"
#include "parser.h"
#include "executor.h"
#include "token.h"

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
    Tokenizer tokenizer;
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

        std::vector<Token> tokens = tokenizer.tokenize(command);
        Parser parser(tokens);
        // executor.execute(cmd);
    }
}
