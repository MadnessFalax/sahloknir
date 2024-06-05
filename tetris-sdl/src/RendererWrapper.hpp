#pragma once

#include "include/SDL2/SDL.h"
#include "WindowWrapper.hpp"

class RendererWrapper {
public:
    SDL_Renderer* renderer = nullptr;

    RendererWrapper(WindowWrapper* w_window) {
        renderer = SDL_CreateRenderer(w_window->window, -1, SDL_RENDERER_ACCELERATED);
    }

    ~RendererWrapper() {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
};