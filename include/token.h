#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    WORD,
    PIPE,       // |
    AND,        // &&
    OR,         // ||
    SEQUENCE,   // ;
    REDIRECT,   // > >> < 2>
    END
};

struct Token {
    TokenType type;
    std::string value;
};

#endif