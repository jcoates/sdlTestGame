#include <iostream>
#include <SDL2/SDL.h>


#include "sdl_graphics.h"

using namespace std;

int main() {
    SDLGraphics graphics;

    SDL_Surface *background = graphics.load_surface((std::string) "../res/blankground.png");
    if (background == NULL) {
        printf("OH NO!\n");
    }
    graphics.draw_scene(*background);
    graphics.shutdown();
    graphics.free_surface(*background);
    background = NULL;

    return 0;
}