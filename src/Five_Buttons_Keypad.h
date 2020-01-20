#ifndef FIVE_BUTTONS_KEYPAD_H
#define FIVE_BUTTONS_KEYPAD_H


/* Attributes */
#include "E_BUTTON_ID.h"


/* Realized interfaces */


/* Needed interfaces */
#include "i_Analogic_Input.h"


/* Events */
#include "Event.h"
#include "ev_Any_Button_Pressed.h"


class Five_Buttons_Keypad {
public :
    /*--------------------------------------------------------------------------------------------*/
    /* Constructor */
	Five_Buttons_Keypad( void ) {}
    Five_Buttons_Keypad( 
		i_Analogic_Input* an_analogic_input,
		Event* ev_select_button_pressed,
		Event* ev_up_button_pressed,
		Event* ev_down_button_pressed,
		Event* ev_left_button_pressed,
		Event* ev_right_button_pressed,
		ev_Any_Button_Pressed* ev_any_button_pressed  );


    /*--------------------------------------------------------------------------------------------*/
    /* Component_Type_Operations */
    void Cyclic(void);


    /*--------------------------------------------------------------------------------------------*/
    /* Event reception points accessors */


    /*--------------------------------------------------------------------------------------------*/
    /* Prodided port accessors */

private :
    typedef enum KEYPAD_STATE { KEYPAD_PRESSED, KEYPAD_RELEASED } KEYPAD_STATE;

    /*--------------------------------------------------------------------------------------------*/
    /* Private attributes */
    E_BUTTON_ID button_pressed;


    /*--------------------------------------------------------------------------------------------*/
    /* Private methods */


    /*--------------------------------------------------------------------------------------------*/
    /* Requirer_Ports */
    i_Analogic_Input* Analog_Pin;


    /*--------------------------------------------------------------------------------------------*/
    /* Provider ports */


    /*--------------------------------------------------------------------------------------------*/
    /* Sent events */
    Event* Select_Button_Pressed;
    Event* Up_Button_Pressed;
    Event* Down_Button_Pressed;
    Event* Left_Button_Pressed;
    Event* Right_Button_Pressed;
    ev_Any_Button_Pressed* Any_Button_Pressed;


    /*--------------------------------------------------------------------------------------------*/
    /* Received events */

};

#endif