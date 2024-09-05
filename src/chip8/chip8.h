#ifndef CHIP8_H
#define CHIP8_H

#include <SDL2/SDL.h>
#include <stdbool.h>

// Emulator states
typedef enum {
    QUIT,
    RUNNING,
    PAUSED,
} emulator_state_t;

// CHIP8 machine object
typedef struct {
    emulator_state_t state;
} chip8_t;

// Initialize CHIP8 machine
bool init_chip8(chip8_t *chip8);
void handle_input(chip8_t *chip8);

#endif // CHIP8_H
