#include "config.h"
#include "sdl_init.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Initialize emu config
  config_t config = {0};
  if (!set_config_from_args(&config, argc, argv))
    exit(EXIT_FAILURE);

  // Init init_sdl
  sdl_t sdl = {0};
  if (!init_sdl(&sdl, config))
    exit(EXIT_FAILURE);

  // Final cleanup
  final_cleanup(sdl);

  exit(EXIT_SUCCESS);
}
