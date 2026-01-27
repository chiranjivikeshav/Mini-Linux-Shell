#ifndef PARSER_H
#define PARSER_H

#include "ASTNode.h"
#include "token.h"
#include "redirection.h"
#include <vector>
#include <memory>

class Parser
{
public:
    Parser(std::vector<Token>& tokens);
    std::unique_ptr<ASTNode> parse();
private:
    std::vector<Token>& tokens;
    size_t pos = 0;
    
    std::unique_ptr<ASTNode> parseSequence();
    std::unique_ptr<ASTNode> parseLogical();
    std::unique_ptr<ASTNode> parsePipeline();
    std::unique_ptr<ASTNode> parsePrimary();
    std::unique_ptr<ASTNode> parseCommand();

    void setRedirectionType(const std::string& arg, Redirection& rd);

    bool match(TokenType type);
    const Token& peek();
};

#endif