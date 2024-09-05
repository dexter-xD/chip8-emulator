#include "chip8.h"

bool init_chip8(chip8_t *chip8) {
    chip8->state = RUNNING; // Default machine state to on/running
    return true;
}

void handle_input(chip8_t *chip8) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                // exit window
                chip8->state = QUIT;
                return;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        chip8->state = QUIT;
                        return;
                    default:
                        break;
                }
            case SDL_KEYUP:
                break;
            default:
                break;
        }
    }
}
