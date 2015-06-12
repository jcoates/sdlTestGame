// game_events.cpp - implementation for the game_events representation
//
// Created by Joshua Coates on 6/12/15.
//

#include "game_events.h"

Event::Event(event_type t, event_data d) {
    type = t;
    data = d;
}

Event::Event(event_type) {
    type = t;
}

bool Event::is_type(event_type t) {
    return (type == t);
}

event_data *Event::get_data() {
    return *data;
}
