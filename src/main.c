#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands/commands.h"

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    while (1) {
        printf("$ ");

        char input[100];
        fgets(input, 100, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        if (handle_buildin_command(input)) {
            continue;
        }

        printf("%s: command not found\n", input);
    }
    return 0;
}
