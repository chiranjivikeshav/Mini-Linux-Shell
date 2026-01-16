#include<iostream>
#include<string>
#include "../include/shell.h"
void Shell::run()
{
    while (true)
    {
        std::cout << "$ ";
        std::string line;
        std::getline(std::cin, line);

        if (line == "exit")
        {
            return;
        }

        // execute(line);
    }
}
