// game_events.h - a representation of events to deal with within the game
//
// Created by Joshua Coates on 6/12/15.
//

#ifndef TESTSTRUCTUREDGAME_GAME_EVENTS_H
#define TESTSTRUCTUREDGAME_GAME_EVENTS_H

enum class event_type {
    //Window Events
            WINDOW_FOCUS,
    WINDOW_UNFOCUS,
    WINDOW_CLOSE,
    WINDOW_MINIMIZE,
    WINDOW_RESTORE,
    WINDOW_MAXIMIZE,
    WINDOW_RESIZE,
    //Mouse Events
            MOUSE_DOWN,
    MOUSE_UP,
    MOUSE_MOVE,
};

//Additional data required by events
union event_data {
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

class Event {
public:
    Event(event_type t, event_data d);

    Event(event_type t);

    bool is_type(event_type t);

    event_data *get_data();

private:
    event_type type;
    event_data data;
};

#endif //TESTSTRUCTUREDGAME_GAME_EVENTS_H
