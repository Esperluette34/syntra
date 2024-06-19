#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

char* readFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filePath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = malloc(length + 1);
    if (content == NULL) {
        fprintf(stderr, "Could not allocate memory for file content\n");
        fclose(file);
        return NULL;
    }

    fread(content, 1, length, file);
    content[length] = '\0';

    fclose(file);
    return content;
}

int main(int ac, char **av){

    if (ac < 2){
        fprintf(stderr, "ratio");
        return 84;
    }
    lexer_t lex;
    lex.txt = readFile(av[1]);
    if (lex.txt == NULL)
        return 84;
    lex.pos = 0;
    token_t tk;
    tk.type = 10;
    while (tk.type != TOKEN_EOF){
        tk = lexer_get_next(&lex);
        if (tk.type == TOKEN_NUM)
            printf("NUM %d\n", tk.n);
        if (tk.type == TOKEN_ADD)
            printf("ADD\n");
        if (tk.type == TOKEN_SUB)
            printf("SUB\n");
    }
    return 0;
}
