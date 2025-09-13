CC=gcc
CFLAGS=-O2 -std=c11 -Wall -Wextra -Iinclude
LDFLAGS=-lm

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
BIN=math_suite

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f src/*.o $(BIN)

.PHONY: all clean