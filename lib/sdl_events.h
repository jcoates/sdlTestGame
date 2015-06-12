// sdl_events.h - wraps an sdl_PollEvent method
//
// Created by Joshua Coates on 6/12/15.
//

#ifndef TESTSTRUCTUREDGAME_SDL_EVENTS_H
#define TESTSTRUCTUREDGAME_SDL_EVENTS_H

#include "hardware_events.h"
#include <SDL2/SDL.h>

class SDLEventManager {
private:
    SDL_Event event;
public:
    /***
     * The wrapper for the SDL_PollEvent function, including only events needed for this game.
     *
     * @e an Event which will be filled with the polled event
     *
     * @return A boolean representing whether or not an event was polled
     */
    bool poll(HardwareEvent *e);
};

#endif //TESTSTRUCTUREDGAME_SDL_EVENTS_H
