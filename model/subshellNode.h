#ifndef SUBSHELLNODE_H
#define SUBSHELLNODE_H

#include "ASTNode.h"

#include "redirection.h"
#include <vector>

struct SubshellNode : ASTNode {
    std::unique_ptr<ASTNode> child;
    std::vector<Redirection> redirections;

    SubshellNode() {
        type = NodeType::SUBSHELL;
    }
};

#endif