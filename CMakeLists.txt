cmake_minimum_required(VERSION 3.10)
project(chip8)

set(CMAKE_C_STANDARD 99)

# Add source files
add_executable(${PROJECT_NAME}
    src/main.c
    src/chip8.c
    src/chip8_op.c
    src/sdl_config.c
)
target_include_directories(${PROJECT_NAME} PRIVATE include)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
