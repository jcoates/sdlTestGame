// sdl_events.cpp - includes implementation of SDL_PollEvent wrapper
//
// Created by Joshua Coates on 6/12/15.
//

#include "sdl_events.h"

bool SDLEventManager::poll(HardwareEvent *e) {
    if (SDL_PollEvent(&event) == 0) {
        hw_event_data *ed = new hw_event_data;
        switch (event.type) {
            case SDL_QUIT:
                *e = HardwareEvent(hw_event_type::QUIT);
                return true;
            case SDL_MOUSEMOTION:
                ed->x = event.button.x;
                ed->y = event.button.y;
                *e = HardwareEvent(hw_event_type::MOUSE_MOVE, *ed);
                return true;
            case SDL_MOUSEBUTTONDOWN:
                ed->x = event.button.x;
                ed->y = event.button.y;
                *e = HardwareEvent(hw_event_type::MOUSE_DOWN, *ed);
                return true;
            case SDL_MOUSEBUTTONUP:
                ed->x = event.button.x;
                ed->y = event.button.y;
                *e = HardwareEvent(hw_event_type::MOUSE_UP, *ed);
                return true;
        }
    } else {
        *e = HardwareEvent();
        return false;
    }
}