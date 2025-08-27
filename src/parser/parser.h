#define MAX_TOKEN_LEN 256
#define MAX_TOKENS 100

typedef enum {
    TOKEN_WORD,
    TOKEN_QUOTED_STRING,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LEN];
} Token;

typedef struct {
    char *input;
    int position;
    int length;
} Lexer;

Lexer* init_lexer(char *input);
void skip_whitespace(Lexer *lexer);
Token read_word(Lexer *lexer);
Token read_quoted_string(Lexer *lexer);
Token next_token(Lexer *lexer);
void free_lexer(Lexer *lexer);
