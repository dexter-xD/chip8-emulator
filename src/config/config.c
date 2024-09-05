#include "config.h"

bool set_config_from_args(config_t *config, const int argc, char **argv) {
    // Set defaults
    *config = (config_t){
        .window_width = 64,     // X resolution
        .window_height = 32,    // Y resolution
        .fg_color = 0xFFFFFFFF, // WHITE
        .bg_color = 0xFFFF00FF, // YELLOW
        .scale_factor = 20,     // Default resolution will be 1280x640
    };

    // Override defaults from passed-in arguments
    for (int i = 1; i < argc; i++) {
        (void)argv[i];
    }

    return true;
}
