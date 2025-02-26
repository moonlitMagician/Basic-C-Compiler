#include "evaluator.h"
#include <stdlib.h>
#include <stdio.h>

int evaluate(ASTNode *node){
    switch (node->type)
    {
    case NODE_NUMBER:
        return node->number;
        break;
    
    case NODE_BINARY_OP:
        int left = evaluate(node->binaryOp.left);
        int right = evaluate(node->binaryOp.right);
        printf("EXEC BINARY OP: %d %c %d\n", left, node->binaryOp.op, right);
        switch (node -> binaryOp.op)
        {
        case TOKEN_PLUS:
            return left + right;
            break;
        
        case TOKEN_MINUS:
            return left - right;
            break;
        
        case TOKEN_MULTIPLY:
            return left * right;
            break;
        
        case TOKEN_DIVIDE:
            return left / right;
            break;
            
        
        default:
            printf("ERR EXPECT NUMBER");
            exit(1);

        }
    
    default:
        printf("ERR UNKNOWN NODE");
        exit(1);

    }
}