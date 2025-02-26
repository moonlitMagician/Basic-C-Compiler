#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_END
} TokenType;

typedef struct 
{
    TokenType type;
    int value;
} Token;

Token getNextToken(const char **input);


#endif