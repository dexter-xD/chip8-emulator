#include "config.h"
#include "sdl_init.h"
#include "chip8.h"

// main
int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    // Initialize emu config
    config_t config = {0};
    if (!set_config_from_args(&config, argc, argv))
        exit(EXIT_FAILURE);

    // Init SDL
    sdl_t sdl = {0};
    if (!init_sdl(&sdl, config))
        exit(EXIT_FAILURE);

    // Initialize CHIP8 machine
    chip8_t chip8 = {0};
    if (!init_chip8(&chip8))
        exit(EXIT_FAILURE);

    // Initialize screen clear to background color
    clear_screen(sdl, config);

    // Main emulator loop
    while (chip8.state != QUIT) {
        // Handle inputs
        handle_input(&chip8);

        // Delay for 60hz/60fps
        SDL_Delay(16);

        // Update window with changes
        update_screen(sdl);
    }

    // Final cleanup
    final_cleanup(sdl);

    exit(EXIT_SUCCESS);
}
