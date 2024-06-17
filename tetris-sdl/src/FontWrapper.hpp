#pragma once

#include <iostream>
#include <string>
#include "RendererWrapper.hpp"
#include "include/SDL2/SDL_ttf.h"

class FontWrapper {

public:
    RendererWrapper* rend;
    TTF_Font* font;

    FontWrapper(std::string real_path, RendererWrapper* renderer) {
        font = TTF_OpenFont(real_path.c_str(), 24);
        if (font == nullptr) {
            std::cout << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        }
        rend = renderer;
    }

    ~FontWrapper() {
        rend = nullptr;

        TTF_CloseFont(font);
        font = nullptr;
    }
};