// Graphics Header : Declares graphics class
//
// Created by Joshua Coates on 5/15/15.
//

#ifndef TESTSTRUCTUREDGAME_GRAPHICS_H
#define TESTSTRUCTUREDGAME_GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include "scene.h"

class SDLGraphics {
private:
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;

    /**
     * loads an image to a texture
     *
     * @arg path the path to the image to load
     * @retval the pointer to the image, or null if the load failed
     */
    SDL_Texture *load_texture(std::string path);

public:
    /**
     * initializes the graphics engine.
     *
     * @retval whether or not the initialization succeeded
     */
    bool init();

    /**
     * draws the scene.
     *
     * @arg scene the scene to draw
     */
    void draw_scene(Scene &scene);

    /**
     * shuts down the graphics engine.
     */
    void shutdown();
};

#endif //TESTSTRUCTUREDGAME_GRAPHICS_H
