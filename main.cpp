#include <iostream>
#include <SDL2/SDL.h>


#include "sdl_graphics.h"

using namespace std;

int main() {
    //Initialize SDL_Graphics
    SDLGraphics graphics;
    graphics.init();

    //Create example scene
    //TODO: try putting ImageData as a const into a separate file
    ImageData ex_menu = ImageData("res/ex_menu.png", 320, 240);
    Image background = Image(&ex_menu, 0, 0);
    Scene exs = Scene(background);

    //TODO: Move game running stuff into a separate place
    //Mock up a game loop
    bool quit = false;
    SDL_Event e;

    //While application is running
    while (!quit) {
        graphics.draw_scene(exs);
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    //Done
    graphics.shutdown();

    return 0;
}