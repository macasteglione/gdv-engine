/**
 * @file Window.h
 * @author Casteglione Matias
 * @brief Header file for window configuration
 * @version 0.1
 * @date 2024-12-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>

class Window {
    const char *pTitle;
    int mWidth;
    int mHeight;
    int mFrameRate;
    bool mQuit;
    SDL_Window *pGraphicsApplicationWindow;
    SDL_GLContext mGLContext;
    SDL_Event mEvent{};

    void handlePreDraw();
    void handleDraw();
    static void setGLAttributes();
    static void handleError(const std::string &message);

  public:
    Window(const char *title, int width, int height, int frameRate = 60);
    ~Window();
    int getX() const;
    int getY() const;
    bool isOpen() const;
    SDL_Event getEvent() const;
    int pollEvents();
    void close();
    void update();
};

#endif // WINDOW_H