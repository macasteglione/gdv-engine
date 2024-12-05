#include "../include/window.h"

void handleInput(Window *pWindow) {
    while (pWindow->pollEvents() != 0) {
        switch (pWindow->getEvent().type) {
        case SDL_QUIT:
            pWindow->close();
            break;
        default:
            break;
        }
    }
}

int main() {
    auto *pWindow = new Window("Mi Juego", 800, 600);

    while (!pWindow->isOpen()) {
        handleInput(pWindow);
        pWindow->update();
    }

    return 0;
}