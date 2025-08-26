#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "parser.h"

// Parse and execute echo command
void parse_echo_command(char *input) {
    Lexer *lexer = init_lexer(input);
    Token tokens[MAX_TOKENS];
    int token_count = 0;
    
    // Get all tokens
    Token token;
    while ((token = next_token(lexer)).type != TOKEN_EOF && 
           token_count < MAX_TOKENS) {
        tokens[token_count++] = token;
    }
    
    // Check if it's an echo command
    if (token_count == 0) {
        printf("Error: Empty command\n");
        free_lexer(lexer);
        return;
    }
    
    if (strcmp(tokens[0].value, "echo") != 0) {
        printf("Error: Only 'echo' command is supported\n");
        free_lexer(lexer);
        return;
    }
    
    // Print the arguments (everything after "echo")
    for (int i = 1; i < token_count; i++) {
        if (i > 1) {
            printf(" "); // Space between arguments
        }
        printf("%s", tokens[i].value);
    }

    printf("\n");
    
    free_lexer(lexer);
}

int handle_buildin_command(char *input) {
    //handle the exit command
    if (strncmp(input, "exit", 4) == 0) {
        if (strlen(input) == 4) {
            exit(0);
        } else if (input[4] == ' ') {
            int exit_code = atoi(&input[5]);
            exit(exit_code);
        }
        return 1;
    }

    if (strncmp(input, "echo", 4) == 0) {
        parse_echo_command(input);
        return 1;
    }

    return 0;
}
