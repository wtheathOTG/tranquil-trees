#include "engine/core/InputMan.h"
#include "SDL.h"
#include "engine/core/Engine.h"

engine::InputMan* engine::InputMan::instancePtr;

struct keyMap_s {
    SDL_Scancode left;
    SDL_Scancode right;
    SDL_Scancode up;
    SDL_Scancode down;
};

struct keyStates_s {
    SDL_Scancode left;
    SDL_Scancode right;
    SDL_Scancode up;
    SDL_Scancode down;
};

keyMap_s keyMap = {
    .left = SDL_SCANCODE_A,
    .right = SDL_SCANCODE_D,
    .up = SDL_SCANCODE_W,
    .down = SDL_SCANCODE_S
};

engine::InputMan::InputMan() {
    if (instancePtr == nullptr) {
        instancePtr = this;
    }
}

engine::InputMan::~InputMan() = default;

engine::InputMan &engine::InputMan::instance() {
    if (instancePtr == nullptr) {
        instancePtr = new InputMan();
    }
    return *instancePtr;
}

void engine::InputMan::HandleInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                Engine::instance().isRunning = false;
                break;
            case SDL_KEYDOWN:
                HandleKeyEvent(e.key.keysym.scancode, KEY_DOWN);
                break;
            case SDL_KEYUP:
                HandleKeyEvent(e.key.keysym.scancode, KEY_UP);
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            case SDL_MOUSEMOTION:
                break;
            case SDL_MOUSEWHEEL:
                break;
            default:
                break;
        }
    }
}


void engine::InputMan::HandleKeyEvent(SDL_Scancode scancode, KeyAction action) {

}