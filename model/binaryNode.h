#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "ASTNode.h"

struct BinaryNode: ASTNode
{
    BinaryNode(const NodeType type, std::unique_ptr<ASTNode>l, std::unique_ptr<ASTNode>r)
    {
        this->type = type;
        left = std::move(l);
        right = std::move(r);
    };
};
#endif