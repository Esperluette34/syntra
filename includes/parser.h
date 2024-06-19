#ifndef __PARSER__
    #define __PARSER__

enum TOKENS_LIST {
    TOKEN_EOF,
    TOKEN_NUM,
    TOKEN_ADD,
    TOKEN_SUB
};

typedef struct lexer_s {
    char *txt;
    int pos;
} lexer_t;

typedef struct token_s {
    int type;
    union {
        int n;
        char str[128];
    };
} token_t;

token_t lexer_get_next(lexer_t *lex);


#endif
