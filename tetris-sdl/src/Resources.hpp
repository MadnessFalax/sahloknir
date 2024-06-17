#pragma once

#include <map>
#include <string>
#include "TextureWrapper.hpp"
#include "FontWrapper.hpp"
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"

static std::string dir_path = "X:\\code_repos\\sahloknir\\tetris-sdl\\src\\res\\";

class Resources {
    RendererWrapper* renderer = nullptr;
public:
    std::map<std::string, TextureWrapper*> texture_dictionary = std::map<std::string, TextureWrapper*>();
    std::map<std::string, FontWrapper*> font_dictionary = std::map<std::string, FontWrapper*>();

    Resources(RendererWrapper* rend) {
        renderer = rend;
    }

    ~Resources() {
        renderer = nullptr;
        for(auto pair : texture_dictionary) {
            delete pair.second;
            pair.second = nullptr;
        }

        texture_dictionary.clear();
    
        for(auto pair : font_dictionary) {
            delete pair.second;
            pair.second = nullptr;
        }

        font_dictionary.clear();
    }

    void load_resources() {
        load_textures();

        load_fonts();
    }

private:
    void load_texture(std::string filename) {
        std::string real_path = dir_path + "tiles\\" + filename;
        auto tex = new TextureWrapper(real_path, renderer);
        texture_dictionary[filename] = tex;
    }

    void load_font(std::string filename) {
        std::string real_path = dir_path + "ttf\\" + filename;
        auto font  = new FontWrapper(real_path, renderer);
        font_dictionary[filename] = font;
    }

    void load_textures() {
        load_texture("blue.png");

    }

    void load_fonts() {
        load_font("Consolas.ttf");
    }
};