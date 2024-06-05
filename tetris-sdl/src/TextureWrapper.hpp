#pragma once

#include "include/SDL2/SDL.h"
#include "SurfaceWrapper.hpp"
#include "RendererWrapper.hpp"

#include <string>

class TextureWrapper
{
    SurfaceWrapper* surface = nullptr;

public:
    SDL_Texture* texture = nullptr;

    TextureWrapper(std::string path, RendererWrapper* w_renderer) {
        surface = new SurfaceWrapper(path);
        texture = SDL_CreateTextureFromSurface(w_renderer->renderer, surface->surface);
    }

    TextureWrapper(SurfaceWrapper* w_surface, RendererWrapper* w_renderer) {
        surface = w_surface;
        texture = SDL_CreateTextureFromSurface(w_renderer->renderer, w_surface->surface);
    }

    ~TextureWrapper() {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        delete surface;
        surface = nullptr;
    }
};