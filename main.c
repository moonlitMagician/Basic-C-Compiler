#include "lexer.h"
#include "parser.h"
#include "evaluator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void freeAST(ASTNode *node){
    if (node == NULL) return;
    {
        if (node->type == NODE_BINARY_OP)
        {
            freeAST(node->binaryOp.left);
            freeAST(node->binaryOp.right);
        }
        free(node);
    }
    
}

int main(){
    char input[100];
    printf("Enter A mathematical Expression: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        printf("ERR INPUT FAILURE");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    const char *inputPtr = input;
    ASTNode *ast = parseExpression(&inputPtr);

    if (ast == NULL)
    {
        fprintf(stderr, "ERR PARSE FAILURE\n");
        return 1;
    }
    
    int result = evaluate(ast);
    printf("Result: %d\n", result);

    freeAST(ast);

    return 0;
}