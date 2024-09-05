# CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Chip8Emulator LANGUAGES C)

# Specify C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find SDL2 (using the built-in CMake module for SDL2)
find_package(SDL2 REQUIRED)

# Include directories for config, sdl, and chip8
include_directories(${SDL2_INCLUDE_DIRS} src/config src/sdl src/chip8)

# Source files for the project
set(SOURCES
    src/main.c
    src/config/config.c
    src/sdl/sdl_init.c
    src/chip8/chip8.c
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the SDL2 library
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
