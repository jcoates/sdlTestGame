// game_events.h - a representation of events to deal with within the game
//
// Created by Joshua Coates on 6/12/15.
//

#ifndef TESTSTRUCTUREDGAME_GAME_EVENTS_H
#define TESTSTRUCTUREDGAME_GAME_EVENTS_H

enum class hw_event_type {
    NONE,

    WINDOW_FOCUS,
    WINDOW_UNFOCUS,
    WINDOW_CLOSE,
    WINDOW_MINIMIZE,
    WINDOW_RESTORE,
    WINDOW_MAXIMIZE,

    MOUSE_DOWN,
    MOUSE_UP,
    MOUSE_MOVE,

    QUIT,
};

//Additional data required by events
union hw_event_data {
    //for mouse events
    struct {
        int x;
        int y;
    };
    //for resize event
    struct {
        int w;
        int h;
    };
};

class HardwareEvent {
public:
    HardwareEvent();

    HardwareEvent(hw_event_type t, hw_event_data d);

    HardwareEvent(hw_event_type t);

    bool is_type(hw_event_type t);

    hw_event_data *get_data();

private:
    hw_event_type type;
    hw_event_data data;
};

#endif //TESTSTRUCTUREDGAME_GAME_EVENTS_H
