
CFLAGS=-std=c17 -Wall -Wextra -Werror

build:
	mkdir -p build
	gcc chip8.c -o build/chip8 $(CFLAGS) `sdl2-config --cflags --libs`

run: build
	./build/chip8
