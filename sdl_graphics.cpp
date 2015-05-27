//
// Created by Joshua Coates on 5/15/15.
//

#include "sdl_graphics.h"

bool SDLGraphics::init() {
    //Initialize screen size
    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;

    bool success = false;

    //Initialize Window
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        //Create Window
        gWindow = SDL_CreateWindow("TestGame2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (gWindow != NULL) {
            int imgFlags = IMG_INIT_PNG;
            if (IMG_Init(imgFlags) & imgFlags) {
                gWindowSurface = SDL_GetWindowSurface(gWindow);
                success = true;
            } else {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            }
        }
        else {
            printf("SDL Graphics failed to create window. SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
    } else {
        printf("SDL Graphics failed to initialize. SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

void SDLGraphics::draw_scene(SDL_Surface &scene) {
    SDL_BlitSurface(&scene, NULL, gWindowSurface, NULL);
    SDL_UpdateWindowSurface(gWindow);
}


void SDLGraphics::shutdown() {

    //Destroy Window & Window Surface
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit
    SDL_Quit();
}

//Note: If this fails, will return NULL POINTER!!!
SDL_Surface *SDLGraphics::load_surface(std::string path) {
    //Stores optimized surface
    SDL_Surface *optimizedSurface = NULL;

    //Stores initial surface
    printf(path.c_str());
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != NULL) {
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gWindowSurface->format, NULL);

        if (optimizedSurface == NULL) {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Conversion uses optimizedSurface
        SDL_FreeSurface(loadedSurface);
    }
    else {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }

    return optimizedSurface;
}

void SDLGraphics::free_surface(SDL_Surface &s) {
    SDL_FreeSurface(&s);
}