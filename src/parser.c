#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int is_number(char c){
    return ((c > 47) && (c < 58));
}

int get_number(lexer_t *lex){
    int total = lex->txt[lex->pos] - '0';

    lex->pos += 1;
    while (is_number(lex->txt[lex->pos])){
        total *= 10;
        total += lex->txt[lex->pos] - '0';
        lex->pos += 1;
    }
    lex->pos -= 1;
    return total;
}

token_t lexer_get_next(lexer_t *lex){
    char c = lex->txt[lex->pos];
    token_t tk;

    if (c == ' '){
        while (c == ' '){
            lex->pos += 1;
            c = lex->txt[lex->pos];
        }
    }
    if (c == '\0'){
        tk.type = TOKEN_EOF;
        return tk;
    }
    if (is_number(c)){
        tk.type = TOKEN_NUM;
        tk.n = get_number(lex);
    }
    if (c == '+')
        tk.type = TOKEN_ADD;
    if (c == '-')
        tk.type = TOKEN_SUB;
    lex->pos += 1;
    return tk;
}
