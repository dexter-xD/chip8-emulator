#include "sdl_init.h"

// Initialize SDL
bool init_sdl(sdl_t *sdl, const config_t config) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
    SDL_Log("Could not initialize SDL subsystems! %s\n", SDL_GetError());
    return false;
  }

  sdl->window = SDL_CreateWindow("Chip8 Emulator", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, config.window_width,
                                 config.window_height, 0);

  if (!sdl->window) {
    SDL_Log("Could not create SDL window %s", SDL_GetError());
    return false;
  }

  return true; // Success
}

// Final cleanup
void final_cleanup(const sdl_t sdl) {
  SDL_DestroyWindow(sdl.window);
  SDL_Quit(); // Shut down SDL
}
