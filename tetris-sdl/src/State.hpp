#include "Drawable.hpp"

#include <vector>

class State {
    int grid_width = 10;
    int grid_height = 20;

    std::vector<Drawable*> tetros = std::vector<Drawable*>();

    State() {
    
    }

    void add_tetro(Drawable* tetro) {
        tetros.push_back(tetro);
    }
};