#include <deque>
#include "include/SDL2/SDL.h"

class Benchmark {
    std::deque<double> fps_queue = std::deque<double>();
    int queue_max_size = 30;
    unsigned int frame_start = 0;
    unsigned int fps_timer = 0;
    unsigned int frame_time = 0;
    unsigned int max_fps = 10;
    unsigned int avg_fps = 1;
    unsigned int min_frametime = 1000 / max_fps;

public:
    Benchmark() {

    }

    ~Benchmark() {

    }

    void start() {
        frame_start = SDL_GetTicks();
    }

    int end() {
        frame_time = SDL_GetTicks() - frame_start;

        if (frame_time < min_frametime) {
            SDL_Delay(min_frametime - frame_time);
        }
        
        if (SDL_GetTicks() - fps_timer >= 1000) {
            double fps = 1000 / (frame_time + 0.001);
            fps_queue.push_back(fps);
            if (fps_queue.size() > queue_max_size) {
                fps_queue.pop_front();
            }

            double sum = 0;
            for (auto x : fps_queue) {
                sum += x;
            }

            avg_fps = sum / fps_queue.size();


            fps_timer = SDL_GetTicks();
        }

        return avg_fps;
    }

};