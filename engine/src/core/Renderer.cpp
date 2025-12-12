#include <engine/core/Renderer.h>

SDL_Renderer* renderer = nullptr;

engine::Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

engine::Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer *engine::Renderer::GetRenderer() {
    return renderer;
}


