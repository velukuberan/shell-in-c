CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=shell

$(TARGET): shell.c
	$(CC) $(CFLAGS) shell.c -o $(TARGET)

format:
	clang-format -i *.c

clean:
	rm -f $(TARGET)

.PHONY: format clean
