#include <map>
#include <string>
#include "TextureWrapper.hpp"
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"

static std::string dir_path = "X:\\code_repos\\sahloknir\\tetris-sdl\\src\\res\\tiles\\";

class Resources {
    RendererWrapper* renderer = nullptr;
public:
    std::map<std::string, TextureWrapper*> texture_dictionary = std::map<std::string, TextureWrapper*>();

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
    }

    void load_resources() {
        load_texture("blue.png");
    }

private:
    void load_texture(std::string filename) {
        std::string real_path = dir_path + filename;
        auto tex = new TextureWrapper(real_path, renderer);
        texture_dictionary[filename] = tex;
    }
};