#ifndef REDIRECTION_H
#define REDIRECTION_H

#include<string>

enum class RedirectType
{
    INPUT,    // <
    OUTPUT,   // >
    APPEND,   // >>
    STDERR,   // 2>
};

struct Redirection
{
    RedirectType type;
    std::string file;
};
#endif
