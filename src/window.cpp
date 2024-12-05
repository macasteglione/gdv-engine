#include "../include/window.h"
#include "../vendor/glad/include/glad/glad.h"

#include <SDL2/SDL.h>
#include <cstdio>
#include <stdexcept>

Window::Window(const char *title, int width, int height, int frameRate)
    : pTitle(title), mWidth(width), mHeight(height), mFrameRate(frameRate),
      pGraphicsApplicationWindow(nullptr), mGLContext(nullptr), mQuit(false) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        handleError("SDL2 no se ha inicializado correctamente");

    setGLAttributes();

    pGraphicsApplicationWindow =
        SDL_CreateWindow(pTitle, 0, 0, mWidth, mHeight, SDL_WINDOW_OPENGL);

    if (pGraphicsApplicationWindow == nullptr)
        handleError("No se ha podido crear la ventana\n");

    mGLContext = SDL_GL_CreateContext(pGraphicsApplicationWindow);

    if (mGLContext == nullptr)
        handleError("No se ha podido crear el contexto OpenGL\n");

    if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
        handleError("No se ha inicializado GLAD\n");
}

Window::~Window() {
    SDL_GL_DeleteContext(mGLContext);
    SDL_DestroyWindow(pGraphicsApplicationWindow);
    SDL_Quit();
}

void Window::update() {
    handlePreDraw();
    handleDraw();
    SDL_GL_SwapWindow(pGraphicsApplicationWindow);
}

void Window::handleError(const std::string &message) {
    const char *error = SDL_GetError();
    if (*error != '\0')
        throw std::runtime_error(message + ": " + error);
}

void Window::setGLAttributes() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

int Window::pollEvents() { return SDL_PollEvent(&mEvent); }

void Window::close() { mQuit = true; }

int Window::getX() const { return mWidth; }

int Window::getY() const { return mHeight; }

bool Window::isOpen() const { return mQuit; }

SDL_Event Window::getEvent() const { return mEvent; }

void Window::handlePreDraw() {}

void Window::handleDraw() {}
