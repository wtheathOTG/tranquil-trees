#pragma once
#include "SDL.h"

namespace engine {
    class Engine {
    public:
        bool isRunning;

        Engine();
        ~Engine();

        static Engine& instance();

        void Init(const char* title, int width, int height);
        SDL_Window* GetWindow();
        SDL_Renderer* GetRenderer();
    private:
        static Engine* instancePtr;

        SDL_Window* window;
        SDL_Renderer* renderer;
    };
}
