#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chip8.h"

int main(int argc, char **argv) {
    // Default Usage message for args
    if (argc < 2) {
       fprintf(stderr, "Usage: %s <rom_name>\n", argv[0]);
       exit(EXIT_FAILURE);
    }

    // Initialize emulator configuration/options
    config_t config = {0};
    if (!set_config_from_args(&config, argc, argv)) exit(EXIT_FAILURE);

    // Initialize SDL
    sdl_t sdl = {0};
    if (!init_sdl(&sdl, &config)) exit(EXIT_FAILURE);

    // Initialize CHIP8 machine
    chip8_t chip8 = {0};
    const char *rom_name = argv[1];
    if (!init_chip8(&chip8, config, rom_name)) exit(EXIT_FAILURE);

    // Initial screen clear to background color
    clear_screen(sdl, config);

    // Seed random number generator
    srand(time(NULL));

    // Main emulator loop
    while (chip8.state != QUIT) {
        // Handle user input
        handle_input(&chip8, &config);

        if (chip8.state == PAUSED) continue;

        // Get time before running instructions
        const uint64_t start_frame_time = SDL_GetPerformanceCounter();

        // Emulate CHIP8 Instructions for this emulator "frame" (60hz)
        for (uint32_t i = 0; i < config.insts_per_second / 60; i++) {
            emulate_instruction(&chip8, config);

            // If drawing on CHIP8, only draw 1 sprite this frame (display wait)
            if ((config.current_extension == CHIP8) &&
                (chip8.inst.opcode >> 12 == 0xD))
                break;
        }

        // Get time elapsed after running instructions
        const uint64_t end_frame_time = SDL_GetPerformanceCounter();

        // Delay for approximately 60hz/60fps (16.67ms) or actual time elapsed
        const double time_elapsed = (double)((end_frame_time - start_frame_time) * 1000) / SDL_GetPerformanceFrequency();

        SDL_Delay(16.67f > time_elapsed ? 16.67f - time_elapsed : 0);

        // Update window with changes every 60hz
        if (chip8.draw) {
          update_screen(sdl, config, &chip8);
          chip8.draw = false;
        }

        // Update delay & sound timers every 60hz
        update_timers(sdl, &chip8);
    }

    // Final cleanup
    final_cleanup(sdl);

    exit(EXIT_SUCCESS);
}
