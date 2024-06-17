#include <string>
#include "SurfaceWrapper.hpp"
#include "FontWrapper.hpp"
#include "Resources.hpp"
#include "TextureWrapper.hpp"
#include "vector.hpp"

class Text {

    SDL_Color col = {0, 0, 0, 0};
    std::string _text = "";
    FontWrapper* _font = nullptr;
    vector2 pos0 = {0, 0};
    vector2 pos1 = {0, 0};
    TextureWrapper* tex = nullptr;


public: 
    Text(FontWrapper* font, std::string text, SDL_Color color) {
        _font = font; 
        _text = text;
        col = color;

        SDL_Surface* tmp_surf = TTF_RenderUTF8_Solid(font->font, text.c_str(), col);

        tex = new TextureWrapper(tmp_surf, _font->rend);

        tmp_surf = nullptr;
    }

    ~Text() {
        _font = nullptr;
        delete tex;
        tex = nullptr;
    }

    void draw(vector2 position) {
        SDL_Rect rect = {position.x, position.y, get_width(), get_height()};
        SDL_RenderCopy(_font->rend->renderer, tex->texture, nullptr, &rect);  
    }

    int get_width() {
        return tex->get_width();
    }

    int get_height() {
        return tex->get_height();
    }
};