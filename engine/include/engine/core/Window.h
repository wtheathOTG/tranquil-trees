#pragma once
#include <SDL_video.h>

namespace engine {
    class Window {
    public:
        Window(const char* title, int width, int height);
        ~Window();

        SDL_Window* GetWindow();
    };
}
