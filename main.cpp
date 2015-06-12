#include <iostream>


#include "sdl_graphics.h"
#include "sdl_events.h"

using namespace std;

int main() {
    //Initialize SDL_Graphics
    SDLGraphics graphics;
    graphics.init();

    SDLEventManager eventsManager;

    //Create example scene
    //TODO: try putting ImageData as a const into a separate file
    ImageData ex_menu = ImageData("res/ex_menu.png", 320, 240);
    Image background = Image(&ex_menu, 0, 0);

    ImageData ex_setting = ImageData("res/settings_trans.png", 160, 50);
    Image button = Image(&ex_setting, 80, 180);

    SceneDisplay exs = SceneDisplay(background);
    exs.add_image(button);



    //TODO: Move game running stuff into a separate place
    //Mock up a game loop
    HardwareEvent *e = new HardwareEvent();
    bool quit = false;

    //While application is running
    while (!quit) {
        graphics.draw_scene(exs);
        //Handle events on queue
        if (eventsManager.poll(e)) {
            if (e->is_type(hw_event_type::QUIT)) {
                quit = true;
            }
        }
    }

    //Done
    graphics.shutdown();

    return 0;
}