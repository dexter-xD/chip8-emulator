CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src/config -I./src/sdl $(shell sdl2-config --cflags)
SDL_LIBS = $(shell sdl2-config --libs)

SRC_DIR = src
OBJ_DIR = obj
BIN = chip8

SRC_FILES = $(wildcard $(SRC_DIR)/**/*.c) $(SRC_DIR)/main.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(BIN)

$(BIN): $(OBJ_FILES)
	$(CC) -o $@ $^ $(SDL_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/sdl $(OBJ_DIR)/config
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)
