#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum
{
    NODE_NUMBER,
    NODE_BINARY_OP
} NodeType;

typedef struct ASTNode
{
    NodeType type;
    union
    {
        int number; // used in NODE_NUMBER
        struct
        {
            struct ASTNode *left;
            struct ASTNode *right;
            TokenType op; //used for operator
        } binaryOp;
    };
} ASTNode;

ASTNode *parseExpression(const char **input);

#endif