#define SDL_MAIN_HADNLED
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum Shape { SQUARE, TRIANGLE };

void drawSquare(SDL_Renderer* renderer) {
    SDL_Rect square = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &square);
}

void drawTriangle(SDL_Renderer* renderer) {
    int x1 = SCREEN_WIDTH / 2;
    int y1 = SCREEN_HEIGHT / 4;
    int x2 = SCREEN_WIDTH / 4;
    int y2 = SCREEN_HEIGHT * 3 / 4;
    int x3 = SCREEN_WIDTH * 3 / 4;
    int y3 = SCREEN_HEIGHT * 3 / 4;

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x1, y1, x3, y3);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
}

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("SDL Shapes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create renderer for window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Main loop flag
    bool quit = false;

    // Current shape
    Shape currentShape = SQUARE;

    // Event handler
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            // Handle key press events
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_s:
                        currentShape = SQUARE;
                        break;
                    case SDLK_t:
                        currentShape = TRIANGLE;
                        break;
                    default:
                        break;
                }
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
        SDL_RenderClear(renderer);

        // Draw current shape
        if (currentShape == SQUARE) {
            drawSquare(renderer);
        } else if (currentShape == TRIANGLE) {
            drawTriangle(renderer);
        }

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Destroy renderer
    SDL_DestroyRenderer(renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
