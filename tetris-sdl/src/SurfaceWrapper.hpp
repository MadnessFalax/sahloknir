#pragma once

#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"

#include <string>

class SurfaceWrapper {

public:
    SDL_Surface* surface = nullptr;

    SurfaceWrapper(std::string path) {
        surface = IMG_Load(path.c_str());
    }

    ~SurfaceWrapper() {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
};