#ifndef CHIP8_H
#define CHIP8_H

#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>

// SDL Container object
typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_AudioSpec want, have;
    SDL_AudioDeviceID dev;
} sdl_t;

// Emulator states
typedef enum {
    QUIT,
    RUNNING,
    PAUSED,
} emulator_state_t;

// CHIP-8 extensions/quirks support
typedef enum {
    CHIP8,
    SUPERCHIP,
    XOCHIP,
} extension_t;

// Emulator configuration object
typedef struct {
    uint32_t window_width;      // SDL window width
    uint32_t window_height;     // SDL window height
    uint32_t fg_color;          // Foreground color RGBA8888
    uint32_t bg_color;          // Background color RGBA8888
    uint32_t scale_factor;      // Amount to scale a CHIP8 pixel by e.g. 20x will be a 20x larger window
    bool pixel_outlines;        // Draw pixel "outlines" yes/no
    uint32_t insts_per_second;  // CHIP8 CPU "clock rate" or hz
    uint32_t square_wave_freq;  // Frequency of square wave sound e.g. 440hz for middle A
    uint32_t audio_sample_rate;
    int16_t volume;             // How loud or not is the sound
    float color_lerp_rate;      // Amount to lerp colors by, between [0.1, 1.0]
    extension_t current_extension;  // Current quirks/extension support for e.g. CHIP8 vs. SUPERCHIP
} config_t;

// CHIP8 Instruction format
typedef struct {
    uint16_t opcode;
    uint16_t NNN;   // 12 bit address/constant
    uint8_t NN;     // 8 bit constant
    uint8_t N;      // 4 bit constant
    uint8_t X;      // 4 bit register identifier
    uint8_t Y;      // 4 bit register identifier
} instruction_t;

// CHIP8 Machine object
typedef struct {
    emulator_state_t state;
    uint8_t ram[4096];
    bool display[64*32];    // Emulate original CHIP8 resolution pixels
    uint32_t pixel_color[64*32];    // CHIP8 pixel colors to draw
    uint16_t stack[12];     // Subroutine stack
    uint16_t *stack_ptr;
    uint8_t V[16];          // Data registers V0-VF
    uint16_t I;             // Index register
    uint16_t PC;            // Program Counter
    uint8_t delay_timer;    // Decrements at 60hz when >0
    uint8_t sound_timer;    // Decrements at 60hz and plays tone when >0
    bool keypad[16];        // Hexadecimal keypad 0x0-0xF
    const char *rom_name;   // Currently running ROM
    instruction_t inst;     // Currently executing instruction
    bool draw;              // Update the screen yes/no
} chip8_t;

// Function declarations
bool init_sdl(sdl_t *sdl, config_t *config);
void final_cleanup(const sdl_t sdl);
void audio_callback(void *userdata, uint8_t *stream, int len);
bool set_config_from_args(config_t *config, const int argc, char **argv);
bool init_chip8(chip8_t *chip8, const config_t config, const char rom_name[]);
void clear_screen(const sdl_t sdl, const config_t config);
void update_screen(const sdl_t sdl, const config_t config, chip8_t *chip8);
void handle_input(chip8_t *chip8, config_t *config);
void emulate_instruction(chip8_t *chip8, const config_t config);
void update_timers(const sdl_t sdl, chip8_t *chip8);

uint32_t color_lerp(const uint32_t start_color, const uint32_t end_color, const float t);

#endif
