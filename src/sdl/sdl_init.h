#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "config.h"

// SDL container object
typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} sdl_t;

// Initialize SDL
bool init_sdl(sdl_t *sdl, const config_t config);
void final_cleanup(const sdl_t sdl);
void clear_screen(const sdl_t sdl, const config_t config);
void update_screen(const sdl_t sdl);

#endif // SDL_INIT_H
