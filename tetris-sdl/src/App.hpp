#include "Exception.hpp"
#include "include/SDL2/SDL_main.h"
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"
#include "include/SDL2/SDL_ttf.h"
#include <iostream>
#include "WindowWrapper.hpp"
#include "RendererWrapper.hpp"
#include "Resources.hpp"
#include "Drawable.hpp"
#include "Benchmark.cpp"
#include "Text.hpp"

class App {
    bool should_quit = false;
    WindowWrapper* window = nullptr;
    RendererWrapper* renderer = nullptr;
    Resources* resources = nullptr;
    Benchmark* benchmark = nullptr;
    int avg_fps = 1;
    TTF_Font* font = nullptr;

public:
    App() {

    }

private:
    bool init() {

        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "Unable to initialize SDL_video." << std::endl;
            cleanup();
            return false;
        }

        int formate_flags = IMG_INIT_PNG;

        if(!(IMG_Init(formate_flags) & formate_flags)) {
            std::cout << "Unable to initialize SDL_image." << std::endl;
            return false;
        }

        if (TTF_Init() == -1) {
            std::cout << "SDL_ttf could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
            return false;
        }

        window = new WindowWrapper();
        if (!window->window) {
            std::cout << "Unable to create window." << std::endl;
            return false;
        }

        renderer = new RendererWrapper(window);
        if (!renderer->renderer) {
            std::cout << "Unable tto create geometry renderer." << std::endl;
            return false;
        }

        resources = new Resources(renderer);
        resources->load_resources();

        benchmark = new Benchmark();

        return true;
    };

public:
    void run() {
        if (!init()) {
            std::cout << "Application failed to initialize.";
            return;
        }

        while (!should_quit) {
            benchmark->start();

            handle_events();
            tick();
            draw();

            avg_fps = benchmark->end();
        }

    }

    void cleanup() {
        if (benchmark) {
            delete benchmark;
        }
        if (resources) {
            delete resources;
        }
        if (renderer) {
            delete renderer;
        }
        if (window) {
            delete window;
        }

        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

private:
    void handle_events() {
        SDL_Event e;
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                should_quit = true;
            }
        }
    }

    void tick() {

    }

    void draw() {
        clear_screen();
        draw_grid();

        auto tmp = new Drawable({0, 0}, {40, 40}, resources->texture_dictionary["blue.png"]);
        tmp->draw(renderer);
        delete tmp;
        tmp = nullptr;
        
        draw_info();
        SDL_RenderPresent(renderer->renderer);
    }

    void draw_grid() {
        int square_size = 40;

        int width = window->get_width();
        int height = window->get_height();

        for (int x = 0; x < width; x+=square_size) {
            for (int y = 0; y < height; y+=square_size) {
                SDL_Rect rect = {x, y, square_size, square_size};
                SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer->renderer, &rect);
            }
        }

    }

    void draw_info() {
        draw_fps();
    }

    void draw_fps() {
        Text* t = new Text(resources->font_dictionary["Consolas.ttf"], std::to_string(avg_fps), {255, 0, 0, 255});
        t->draw({0, 0});
        delete t;
        t = nullptr;
    }

    void clear_screen() {
        SDL_SetRenderDrawColor(renderer->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer->renderer);
    }

};
