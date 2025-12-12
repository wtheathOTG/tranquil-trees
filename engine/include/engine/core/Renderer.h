#pragma once
#include <SDL_render.h>

namespace engine {
    class Renderer {
    public:
        Renderer(SDL_Window* window);
        ~Renderer();

        SDL_Renderer* GetRenderer();
    };
}
