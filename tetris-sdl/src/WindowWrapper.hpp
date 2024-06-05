#pragma once
#include "include/SDL2/SDL.h"

class WindowWrapper {
    int window_width = 800;
    int window_height = 600;

public:
    SDL_Window* window = nullptr;

    WindowWrapper() {
        window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0x0);
    }

    ~WindowWrapper() {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    int get_height() {
        return window_height;
    }

    int get_width() {
        return window_width;
    }
};