// Graphics Header : Declares graphics class
//
// Created by Joshua Coates on 5/15/15.
//

#ifndef TESTSTRUCTUREDGAME_GRAPHICS_H
#define TESTSTRUCTUREDGAME_GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>

class SDLGraphics {
private:
    SDL_Window *gWindow;
    SDL_Surface *gWindowSurface;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
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
    void draw_scene(SDL_Surface &scene);

    /**
     * shuts down the graphics engine.
     */
    void shutdown();

    /**
     * loads a surface and optimizes it for the screen
     *
     * @arg path the path to the image to load
     * @retval the pointer to the image, or null if the load failed
     */
    SDL_Surface *load_surface(std::string path);

    /**
     * frees a provided surface
     *
     * @arg s the surface to be freed
     */
    void free_surface(SDL_Surface &s);
};

#endif //TESTSTRUCTUREDGAME_GRAPHICS_H
