# pragma once
#include <SDL_events.h>
#include <SDL_scancode.h>

namespace engine {
    enum KeyAction {
        KEY_DOWN,
        KEY_UP,
        KEY_HELD,
    };

    enum Input {
        LEFT,
        RIGHT,
        UP,
        DOWN,
    };

    enum InputAxis {
        MOVE_X,
        MOVE_Y,
    };

    class InputMan {
    public:
        InputMan();
        ~InputMan();

        static InputMan& instance();

        void HandleInput();
        void HandleKeyEvent(SDL_Scancode scancode, KeyAction action);
        bool GetInput(InputAxis axis, KeyAction action);
        int GetInputAxis(InputAxis axis);

    private:
        static InputMan* instancePtr;
    };
}
