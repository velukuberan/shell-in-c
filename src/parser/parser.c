#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "parser.h"

// Initialize lexer
Lexer* init_lexer(char *input) {
    Lexer *lexer = malloc(sizeof(Lexer));
    lexer->input = input;
    lexer->position = 0;
    lexer->length = strlen(input);
    return lexer;
}

// Skip whitespace
void skip_whitespace(Lexer *lexer) {
    while (lexer->position < lexer->length && 
           isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }
}

// Read a word token (unquoted)
Token read_word(Lexer *lexer) {
    Token token;
    token.type = TOKEN_WORD;
    int i = 0;
    
    while (lexer->position < lexer->length && 
           !isspace(lexer->input[lexer->position]) &&
           lexer->input[lexer->position] != '"' &&
           lexer->input[lexer->position] != '\'') {
        
        if (i < MAX_TOKEN_LEN - 1) {
            token.value[i++] = lexer->input[lexer->position];
        }
        lexer->position++;
    }
    
    token.value[i] = '\0';
    return token;
}

// Read a quoted string (double or single quotes)
Token read_quoted_string(Lexer *lexer) {
    Token token;
    token.type = TOKEN_QUOTED_STRING;
    int i = 0;
    
    char quote_char = lexer->input[lexer->position];
    lexer->position++; // Skip opening quote
    
    while (lexer->position < lexer->length && 
           lexer->input[lexer->position] != quote_char) {
        
        if (i < MAX_TOKEN_LEN - 1) {
            token.value[i++] = lexer->input[lexer->position];
        }
        lexer->position++;
    }
    
    if (lexer->position < lexer->length) {
        lexer->position++; // Skip closing quote
    }
    
    token.value[i] = '\0';
    return token;
}

// Get next token
Token next_token(Lexer *lexer) {
    Token token;
    
    skip_whitespace(lexer);
    
    if (lexer->position >= lexer->length) {
        token.type = TOKEN_EOF;
        token.value[0] = '\0';
        return token;
    }
    
    char current_char = lexer->input[lexer->position];
    
    if (current_char == '"' || current_char == '\'') {
        return read_quoted_string(lexer);
    } else {
        return read_word(lexer);
    }
}

void free_lexer(Lexer *lexer) {
    if (lexer) {
        free(lexer);
    }
}
