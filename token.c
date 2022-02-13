/**
 * @file token.c
 * @date
 * @brief
*/
#include "token.h"

TokenList* init_token_list() 
{
    TokenList* res = calloc(1, sizeof(TokenList));
    res->list = (Token*) calloc(32, sizeof(Token));
    res->cursor = 0;
    res->capacity = 32;

    return res;
}

void push_token(TokenList* chunk, int type)
{
    if (chunk->cursor == chunk->capacity){
        chunk->capacity += 16;
        chunk->list = realloc(chunk->list, chunk->capacity);
    }

    chunk->list[chunk->cursor].type = type;
    chunk->cursor++;
}

void print_token_list(TokenList* chunk)
{
    for (int i = 0; i < chunk->cursor; i++) {
        switch (chunk->list[i].type) {
            case TOKEN_ID : printf("TOKEN_ID\n"); break;
            case TOKEN_STRING : printf("TOKEN_STRING\n"); break;
            case TOKEN_INT : printf("TOKEN_INT\n"); break;
            case TOKEN_SLASH : printf("TOKEN_SLASH\n"); break;
            case TOKEN_STAR : printf("TOKEN_STAR\n"); break;
            case TOKEN_PLUS : printf("TOKEN_PLUS\n"); break;
            case TOKEN_MINUS : printf("TOKEN_MINUS\n"); break;
            case TOKEN_EQ : printf("TOKEN_EQ\n"); break;
            case TOKEN_LT : printf("TOKEN_LT\n"); break;
            case TOKEN_GT : printf("TOKEN_GT\n"); break;
            case TOKEN_COMMA : printf("TOKEN_COMMA\n"); break;
            case TOKEN_COLON : printf("TOKEN_COLON\n"); break;
            case TOKEN_LPAREN : printf("TOKEN_LPAREN\n"); break;
            case TOKEN_RPAREN : printf("TOKEN_RPAREN\n"); break;
            case TOKEN_LBRACKET : printf("TOKEN_LBRACKET\n"); break;
            case TOKEN_RBRACKET : printf("TOKEN_RBRACKET\n"); break;
            case TOKEN_LSQBRACKET : printf("TOKEN_LSQBRACKET\n"); break;
            case TOKEN_RSQBRACKET : printf("TOKEN_RSQBRACKET\n"); break;
            case TOKEN_ASSIGN : printf("TOKEN_ASSIGN\n"); break;
            case TOKEN_PROGRAM : printf("TOKEN_PROGRAM\n"); break;  
            case TOKEN_FUNCTION : printf("TOKEN_FUNCTION\n"); break;
            case TOKEN_PROC : printf("TOKEN_PROC\n"); break;
            case TOKEN_VAR : printf("TOKEN_VAR\n"); break;
            case TOKEN_BEGIN : printf("TOKEN_BEGIN\n"); break;
            case TOKEN_END : printf("TOKEN_END\n"); break; 
            default: printf("UNKOWN_TOKEN\n"); break; // error triger
        }

    }
}

void pop_token_list(TokenList* chunk) 
{
    free(chunk->list);
    chunk->list = NULL;
    free(chunk);
}