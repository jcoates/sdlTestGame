//
// Created by Joshua Coates on 5/15/15.
//

#include <unistd.h>
#include "sdl_graphics.h"

bool SDLGraphics::init() {
    //Initialize screen size
    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;

    bool success = true;

    //Initialize Window
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        //Create Window
        gWindow = SDL_CreateWindow("TestGame2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (gWindow != NULL) {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            }

            //Initialize Renderer
            gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
            if (gRenderer == NULL) {
                printf("SDL could not create renderer. SDL_Error: %s\n", SDL_GetError());
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

void SDLGraphics::draw_scene(Scene &scene) {

    //Clear previous scene
    SDL_RenderClear(gRenderer);

    //Set up background
    SDL_Texture *loading_tex = load_texture(*scene.get_bg()->get_path());
    SDL_RenderCopy(gRenderer, loading_tex, NULL, NULL);

    //Set up images on top of background
    for (std::list<Image>::iterator it = scene.get_imgs()->begin(); it != scene.get_imgs()->end(); it++) {
        //Where to copy image from
        SDL_Rect *src;
        int frames_in_row = it->get_img_width() / it->get_frame_width();
        int theoretical_x = it->get_cur_frame() * it->get_frame_width();
        int frame_row = theoretical_x / frames_in_row;
        int frame_col = theoretical_x % frame_row;
        src->x = frame_col;
        src->y = frame_row * it->get_frame_height();
        src->w = it->get_frame_width();
        src->h = it->get_frame_height();

        //Where to draw image
        SDL_Rect *dst;
        dst->x = it->get_x();
        dst->y = it->get_y();

        //Load image
        loading_tex = load_texture(*it->get_path());

        //Copy image to "canvas"
        SDL_RenderCopy(gRenderer, loading_tex, src, dst);
    }

    //Free stuff
    SDL_DestroyTexture(loading_tex);

    //Make magic happen
    SDL_RenderPresent(gRenderer);
    SDL_UpdateWindowSurface(gWindow);
}


void SDLGraphics::shutdown() {

    //Destroy Renderer
    SDL_DestroyRenderer(gRenderer);

    //Destroy Window & Window Surface
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit
    SDL_Quit();
}

//Note: If this fails, will return NULL POINTER!!!
SDL_Texture *SDLGraphics::load_texture(std::string path) {
    //Stores optimized surface
    SDL_Texture *tex = NULL;

    //Stores initial surface
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != NULL) {
        tex = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

        if (tex == NULL) {
            printf("Unable to create texture from image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Done with this
        SDL_FreeSurface(loadedSurface);
    }
    else {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }

    return tex;
}
