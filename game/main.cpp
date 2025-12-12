#include <cstdio>
#include <SDL.h>

#include "engine/core/Engine.h"
#include "engine/core/InputMan.h"
#include "engine/core/Renderer.h"
#include "engine/core/Window.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(int argc, char* argv[]) {
    new engine::Engine();
    engine::Engine::instance().Init("Tranquil Trees", SCREEN_WIDTH, SCREEN_HEIGHT);

    new engine::InputMan();

    // SDL_SetRenderDrawColor(renderer->GetRenderer(), 0, 0, 0, 255);
    // SDL_RenderClear(renderer->GetRenderer());
    // SDL_RenderPresent(renderer->GetRenderer());
    while (engine::Engine::instance().isRunning) {
        engine::InputMan::instance().HandleInput();
        SDL_Delay(20);
    }


    return 0;
}