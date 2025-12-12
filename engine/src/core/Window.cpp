#include "engine/core/Window.h"

#include <string>

SDL_Window* window;

engine::Window::Window(const char* title, const int width, const int height) {
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );
}

engine::Window::~Window() {
    SDL_DestroyWindow(window);
};

SDL_Window *engine::Window::GetWindow() {
    return window;
}


