#include "parser.h"
#include <stdlib.h>
#include <stdio.h>

ASTNode *createNumberNode(int value)
{
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_NUMBER;
    node->number = value;
    return node;
}

ASTNode *createBinaryOpNode(ASTNode *left, ASTNode *right, TokenType op)
{
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_BINARY_OP;
    node->binaryOp.left = left;
    node->binaryOp.right = right;
    node->binaryOp.op = op;
    return node;
}

//parsing number or expression
ASTNode *parseFactor(const char **input)
{
    Token token = getNextToken(input);
    if (token.type == TOKEN_NUMBER)
    {
        return createNumberNode(token.value);
    }
    else
    {
        printf("ERR EXPECTED NUMBER \n");
        exit(1);
    }
}

ASTNode *parseTerm(const char **input){
    ASTNode *node = parseFactor(input);

    while (1)
    {
        Token token = getNextToken(input);
        if (token.type == TOKEN_END) break;
        if (token.type == TOKEN_MULTIPLY || token.type == TOKEN_DIVIDE){
            ASTNode *right = parseFactor(input);
            node = createBinaryOpNode(node, right, token.type);
            printf("CREATED BINARY OP %c\n", token.type == TOKEN_PLUS ? '+' : '-');
        } else {
            (*input)--;
            break;
        }
    }
    return node;
    
}

ASTNode *parseExpression(const char **input){
    ASTNode *node = parseTerm(input);

    while (1)
    {
        Token token = getNextToken(input);
        if(token.type == TOKEN_END){
            break;
        }
        else if (token.type = TOKEN_PLUS || token.type == TOKEN_MINUS)
        {
            ASTNode *right = parseTerm(input);
            node = createBinaryOpNode(node, right, token.type);
        } else {
            (*input)--;
            break;
        }
        
    }
    return node;
}