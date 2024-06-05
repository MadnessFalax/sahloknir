#include "include/SDL2/SDL.h"
#include "TextureWrapper.hpp"

#include <vector>

struct vector2 {
    int x;
    int y;

    vector2(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

class Drawable {
protected:
    bool _has_texture = false;
    vector2 position = {0, 0};
    vector2 position2 = {1, 1};
    int width = 1;
    int height = 1;
    TextureWrapper* texture = nullptr;
    std::vector<Drawable*> subs = std::vector<Drawable*>();
public:
    Drawable() {

    }

    Drawable(vector2 pos, vector2 pos2, TextureWrapper* tex = nullptr) {
        position = pos;
        position2 = pos2;

        if (tex) {
            texture = tex;
            _has_texture = true;
        }
    }

    Drawable(TextureWrapper* w_texture) {
        texture = w_texture;
        _has_texture = true;
    }

    ~Drawable() {
        texture = nullptr;
        for(auto d : subs) {
            delete d;
            d = nullptr;
        }
    }

    
    void set_pos(vector2 pos) {
        position = pos;
        recount_dimensions();
    }

    void set_pos2(vector2 pos) {
        position2 = pos;
        recount_dimensions();
    }

private:
    void recount_dimensions() {
        width = position2.x - position.x;
        height = position2.y - position.y;
    }

public:
    vector2 get_pos() {
        return position;
    }

    vector2 get_pos2() {
        return position2;
    }

    int get_height() {
        return height;
    }

    int get_width() {
        return width;
    }

    bool has_texture() {
        return _has_texture;
    }

    void draw(RendererWrapper* renderer) {
        SDL_Rect rect = { position.x, position.y, width, height };
        SDL_RenderCopy(renderer->renderer, texture->texture, NULL, &rect);
    }

    void add_sub(Drawable* drawable) {
        subs.push_back(drawable);
    }

    void add_sub(int rel_x, int rel_y) {
        auto tmp = copy();
        auto old_pos = tmp->get_pos();
        auto old_pos2 = tmp->get_pos2();

        tmp->set_pos({ old_pos.x + rel_x, old_pos.y + rel_y });
        tmp->set_pos2({ old_pos2.x + rel_x, old_pos2.y + rel_y });

        add_sub(tmp);
    }

    Drawable* copy() {
        return new Drawable(position, position2, texture);
    }

};