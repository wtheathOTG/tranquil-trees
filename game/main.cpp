#include <cstdio>
#include <SDL.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

void Init();
void Shutdown(int exitCode);

int main(int argc, char* argv[]) {
    Init();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    Shutdown(EXIT_SUCCESS);
    return 0;
}

void Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        Shutdown(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(
        "Tranquil Trees",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0
    );
    if (window == nullptr) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        Shutdown(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        Shutdown(EXIT_FAILURE);
    }
}

void Shutdown(const int exitCode) {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    exit(exitCode);
}