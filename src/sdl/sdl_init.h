#ifndef SDL_INIT_H
#define SDL_INIT_H

#include "config.h"
#include "SDL.h"
#include <stdbool.h>

typedef struct {
  SDL_Window *window;
} sdl_t;

bool init_sdl(sdl_t *sdl, const config_t config);
void final_cleanup(const sdl_t sdl);

#endif // SDL_INIT_H
