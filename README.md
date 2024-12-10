# CHIP-8 Emulator

This project is a CHIP-8 emulator written in C, utilizing SDL2 for graphics and input. This guide will walk you through setting up, compiling, and running the emulator on Linux systems using CMake.

---

## Prerequisites

To build and run this emulator, ensure you have the following installed:

- Linux OS (Tested on Ubuntu 20.04 LTS, but should work on other distributions)
- GCC or another C compiler
- CMake (version 3.10 or higher)
- SDL2 development libraries

---

## Installing Dependencies

### Install CMake
```bash
sudo apt-get update
sudo apt-get install cmake
```

### Install SDL2 Development Libraries
```bash
sudo apt-get install libsdl2-dev
```

---

## Project Setup

### Clone the Repository
```bash
git clone <https://github.com/dexter-xD/chip8-emulator.git
cd chip8-emulator
```

### Directory Structure
Ensure your project structure matches the following:
```
chip8-emulator/
├── include/
│   └── chip8.h
├── src/
│   ├── chip8.c
│   ├── chip8_op.c
│   ├── sdl_config.c
│   └── main.c
└── CMakeLists.txt
```

### Configure the Project
Create a build directory to separate build files from the source:
```bash
mkdir build
cd build
```

Run CMake to generate the build system:
```bash
cmake ..
```

### Build the Project
```bash
make
```

---

## Running the Emulator

Run the compiled executable, providing a ROM file as input:
```bash
./chip8 path/to/your/rom.ch8
```

---

### Observations
- **Visual Tests**: Check for correct screen updates, sprite rendering, and collision detection.
- **Opcode Tests**: Verify that all opcodes are correctly implemented by observing emulator behavior or debug logs.

---

## Troubleshooting

### Common Issues and Fixes
1. **Screen not updating**: Review the `update_screen` function.
2. **Incorrect opcode behavior**: Debug the `emulate_instruction` function.
3. **Sound or timing issues**: Check `update_timers` and SDL audio setup.

---

This guide should help you set up and run your CHIP-8 emulator on Linux. If you encounter any issues, consult the [SDL2](https://wiki.libsdl.org/) and [CMake](https://cmake.org/documentation/) documentation or open an issue in the repository.
```