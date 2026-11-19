CC      := gcc
CFLAGS  := -g -Wall -Wextra -std=c17
SRC     := $(wildcard src/*.c)
OBJ     := $(patsubst src/%.c,build/%.o,$(SRC))
BIN     := build/prog

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ) | build
	$(CC) $(CFLAGS) -o $@ $(OBJ)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c -o $@ $<

build:
	mkdir -p build

clean:
	rm -rf build
