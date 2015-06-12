// game_events.cpp - implementation for the game_events representation
//
// Created by Joshua Coates on 6/12/15.
//

#include "hardware_events.h"

HardwareEvent::HardwareEvent() {
    type = hw_event_type::NONE;
}

HardwareEvent::HardwareEvent(hw_event_type t, hw_event_data d) {
    type = t;
    data = d;
}

HardwareEvent::HardwareEvent(hw_event_type t) {
    type = t;
}

bool HardwareEvent::is_type(hw_event_type t) {
    return (type == t);
}

hw_event_data *HardwareEvent::get_data() {
    return &data;
}
