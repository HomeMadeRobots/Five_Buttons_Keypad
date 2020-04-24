#ifndef E_BUTTON_ID_H
#define E_BUTTON_ID_H

/* Enumerated_Data_Type */
/* Allows to model a data representing the identity of a button of a 5 buttons
keypad. */
typedef enum {
    NO_BUTTON,
    SELECT_BUTTON,
    UP_BUTTON,
    DOWN_BUTTON,
    LEFT_BUTTON,
    RIGHT_BUTTON
} E_Button_Id;

#endif