#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while (1) {
        // Flush after every printf
        setbuf(stdout, NULL);

        // Uncomment this block to pass the first stage
        printf("$ ");

        // Wait for user input
        char input[100];
        fgets(input, 100, stdin);

        input[strcspn(input, "\n")] = '\0';
        printf("%s: command not found\n", input);
    }
    return 0;
}
