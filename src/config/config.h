#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint32_t window_width;
  uint32_t window_height;
} config_t;

bool set_config_from_args(config_t *config, const int argc, char **argv);

#endif // CONFIG_H
