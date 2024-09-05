#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

// Emulator config
typedef struct {
    uint32_t window_width;
    uint32_t window_height;
    uint32_t fg_color;     // foreground color RGBA888
    uint32_t bg_color;     // background color RGBA888
    uint32_t scale_factor; // Amount to scale a CHIP* pixel by 20x
} config_t;

// Set up initial emu config from passed in arguments
bool set_config_from_args(config_t *config, const int argc, char **argv);

#endif // CONFIG_H
