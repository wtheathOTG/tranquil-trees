#include "engine/core/Engine.h"

engine::Engine* engine::Engine::instancePtr;

engine::Engine::Engine() {
    if (instancePtr == nullptr) {
        instancePtr = this;
        isRunning = true;
    }
}

void engine::Engine::Init(const char* title, const int width, const int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

engine::Engine::~Engine() {
    if (renderer != nullptr) SDL_DestroyRenderer(renderer);
    if (window != nullptr) SDL_DestroyWindow(window);
    SDL_Quit();
}

engine::Engine &engine::Engine::instance() {
    if (instancePtr == nullptr) {
        instancePtr = new Engine();
    }
    return *instancePtr;
}