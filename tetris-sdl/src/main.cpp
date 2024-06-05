#include "include/SDL2/SDL_main.h"
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"
#include <stdio.h>
#include "App.hpp"

// // Screen dimension constants
// const int SCREEN_WIDTH = 800;
// const int SCREEN_HEIGHT = 600;
App* application = nullptr;
void cleanup_wrapper();


int main(int argc, char* args[]) {
    atexit(cleanup_wrapper);

    application = new App();
    // // Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    //     printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // // Initialize SDL_image
    // int imgFlags = IMG_INIT_PNG;
    // if (!(IMG_Init(imgFlags) & imgFlags)) {
    //     printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    //     return 1;
    // }

    // // Create window
    // SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // if (window == NULL) {
    //     printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // // Create renderer for window
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // if (renderer == NULL) {
    //     printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // // Load PNG image
    // SDL_Surface* loadedSurface = IMG_Load("X:\\code_repos\\sahloknir\\tetris-sdl\\build\\res\\dirt.png");
    // if (loadedSurface == NULL) {
    //     printf("Unable to load image %s! SDL_image Error: %s\n", "X:\\code_repos\\sahloknir\\tetris-sdl\\build\\res\\dirt.png", IMG_GetError());
    //     return 1;
    // }

    // // Create texture from surface pixels
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    // if (texture == NULL) {
    //     printf("Unable to create texture from %s! SDL_Error: %s\n", "X:\\code_repos\\sahloknir\\tetris-sdl\\build\\res\\dirt.png", SDL_GetError());
    // }

    // // Free loaded surface
    // SDL_FreeSurface(loadedSurface);

    // // Main loop flag
    // int quit = 0;

    // // Event handler
    // SDL_Event e;

    // // While application is running
    // while (!quit) {
    //     // Handle events on queue
    //     while (SDL_PollEvent(&e) != 0) {
    //         // User requests quit
    //         if (e.type == SDL_QUIT) {
    //             quit = 1;
    //         }
    //     }

    //     // Clear screen
    //     SDL_RenderClear(renderer);

    //     // Render texture to screen
    //     SDL_RenderCopy(renderer, texture, NULL, NULL);

    //     // Update screen
    //     SDL_RenderPresent(renderer);
    // }

    // // Free resources and close SDL
    // SDL_DestroyTexture(texture);
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // IMG_Quit();
    // SDL_Quit();

    application->run();

    application->cleanup();
    delete application;
    application = nullptr;

    return 0;
}


void cleanup_wrapper() {
    if (application) {
        application->cleanup();
        delete application;
        application = nullptr;
    }
}