#pragma once

#include "include/SDL2/SDL.h"
#include "SurfaceWrapper.hpp"
#include "RendererWrapper.hpp"

#include <string>

class TextureWrapper
{
    SurfaceWrapper* surface = nullptr;
    int width = 0;
    int height = 0;

public:
    SDL_Texture* texture = nullptr;

    TextureWrapper(std::string path, RendererWrapper* w_renderer) {
        surface = new SurfaceWrapper(path);
        texture = SDL_CreateTextureFromSurface(w_renderer->renderer, surface->surface);

        width = surface->surface->w;
        height = surface->surface->h;
    }

    TextureWrapper(SurfaceWrapper* w_surface, RendererWrapper* w_renderer) {
        surface = w_surface;
        texture = SDL_CreateTextureFromSurface(w_renderer->renderer, w_surface->surface);

        width = surface->surface->w;
        height = surface->surface->h;
    }

    TextureWrapper(SDL_Surface* surf, RendererWrapper* w_renderer) {
        surface = new SurfaceWrapper(surf);
        texture = SDL_CreateTextureFromSurface(w_renderer->renderer, surf);
    
        width = surface->surface->w;
        height = surface->surface->h;
    }

    ~TextureWrapper() {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        delete surface;
        surface = nullptr;
    }

    int get_height() {
        return height;
    }

    int get_width() {
        return width;
    }
};