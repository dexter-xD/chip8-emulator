#include "config.h"
#include <stdio.h>
#include <stdlib.h>

// Set up initial emu config from passed in arguments
bool set_config_from_args(config_t *config, const int argc, char **argv) {

  // Set defaults
  *config = (config_t){
      .window_width = 64,
      .window_height = 32,
  };

  // Override defaults from passed-in arguments
  for (int i = 1; i < argc; i++) {
    (void)argv[i]; // TODO: Handle custom argument logic here
  }

  return true;
}
