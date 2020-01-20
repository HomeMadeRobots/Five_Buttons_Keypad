#ifndef EV_ANY_BUTTON_PRESSED_H
#define EV_ANY_BUTTON_PRESSED_H

#include "Event.h"

#include "E_BUTTON_ID.h"

/* Event_Interface */
/* This event is sent when any switch of a five buttons keypad is pressed. */
class ev_Any_Button_Pressed : public Event {
public :
    /* Event_Arguments */
    E_BUTTON_ID Pressed_Button;
};

#endif
