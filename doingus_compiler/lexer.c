#include "lexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

Token getNextToken(const char **input){
    //skipping whitespace
    while (isspace(**input)) (*input)++;
    {
        if (**input == '\0'){
            printf("TOKEN: END\n");
            return(Token){TOKEN_END, 0};
        }

        if (isdigit(**input)){
            int value = 0;
            while (isdigit(**input))
            {
                //converting numbers to their true numerical value
                value = value * 10 + (**input - '0');
                (*input)++;
            }
            printf("TOKEN: NUMBER(%d)\n", value);
            return (Token){TOKEN_NUMBER, value};           
        }

        Token token;
        switch (**input)
        {
        case '+':
            token.type = TOKEN_PLUS;
            break;
        
        case '-': 
            token.type = TOKEN_MINUS;
            break;
        
        case '*':
            token.type = TOKEN_MULTIPLY;
            break;
        
        case '/':
            token.type = TOKEN_DIVIDE;
            break;

        case '\0':
            token.type = TOKEN_END;
            break;
        
        default:
            printf("ERROR: UNEXPECTED CHAR '%c'\n", **input); exit(1);
            break;
        }
        printf("TOKEN: OP (%c)\n", **input);
        (*input)++;
        return token;

    }
    
}
