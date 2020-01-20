#include "Five_Buttons_Keypad.h"


/**************************************************************************************************/
/* Constructor */
Five_Buttons_Keypad::Five_Buttons_Keypad( 
    i_Analogic_Input* an_analogic_input,
    Event* ev_select_button_pressed,
    Event* ev_up_button_pressed,
    Event* ev_down_button_pressed,
    Event* ev_left_button_pressed,
    Event* ev_right_button_pressed,
    ev_Any_Button_Pressed* ev_any_button_pressed  )
{
    this->Analog_Pin = an_analogic_input;
    this->Select_Button_Pressed = ev_select_button_pressed;
    this->Up_Button_Pressed = ev_up_button_pressed;
    this->Down_Button_Pressed = ev_down_button_pressed;
    this->Left_Button_Pressed = ev_left_button_pressed;
    this->Right_Button_Pressed = ev_right_button_pressed;
    this->Any_Button_Pressed = ev_any_button_pressed;
    this->button_pressed = NO_BUTTON;
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Component_Type_Operations */
void Five_Buttons_Keypad::Cyclic(void)
{
    T_VOLTAGE pin_voltage = 0;
    static KEYPAD_STATE keypad_state = KEYPAD_RELEASED;
    static E_BUTTON_ID last_button_pressed = NO_BUTTON;
    E_BUTTON_ID current_button_pressed = NO_BUTTON;
    

    /* Get the curent pressed button */
    this->Analog_Pin->Get_Voltage( &pin_voltage );

    if( pin_voltage > 1000 )
	{
		current_button_pressed = NO_BUTTON;
	}
	else if( pin_voltage <= 1000 && pin_voltage >800 )
	{
		current_button_pressed = SELECT_BUTTON;
	}
	else if( pin_voltage <= 800 && pin_voltage >600 )
	{
		current_button_pressed = LEFT_BUTTON;
	}
	else if( pin_voltage <= 600 && pin_voltage >400 )
	{
		current_button_pressed = DOWN_BUTTON;
	}
	else if( pin_voltage <= 400 && pin_voltage >200 )
	{
		current_button_pressed = UP_BUTTON;
	}
	else if( pin_voltage <= 200 )
	{
		current_button_pressed = RIGHT_BUTTON;
	}

    if( keypad_state == KEYPAD_RELEASED )
    {
        if( current_button_pressed != NO_BUTTON )
        {
            if( last_button_pressed == current_button_pressed )
            {
                this->button_pressed = current_button_pressed;
                switch( current_button_pressed )
                {
                    case SELECT_BUTTON :
                        this->Select_Button_Pressed->Send();
                        break;
                    case UP_BUTTON :
                        this->Up_Button_Pressed->Send();
                        break;
                    case DOWN_BUTTON :
                        this->Down_Button_Pressed->Send();
                        break;
                    case LEFT_BUTTON :
                        this->Left_Button_Pressed->Send();
                        break;
                    case RIGHT_BUTTON :
                        this->Right_Button_Pressed->Send();
                        break;
                    default :
                        break;
                }
                this->Any_Button_Pressed->Pressed_Button = current_button_pressed;
                this->Any_Button_Pressed->Send();
  
                keypad_state = KEYPAD_PRESSED;
            }
        }
        else /* current_button_pressed == NO_BUTTON */
        {
            /* keypad remains in KEYPAD_RELEASED state */
        }
    }
    else /* keypad_state = PRESSED */
    {
        if( last_button_pressed == NO_BUTTON && current_button_pressed == NO_BUTTON )
        {
            keypad_state = KEYPAD_RELEASED;
        }
    }

    last_button_pressed = current_button_pressed;
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Event reception points accessors */
/**************************************************************************************************/


/**************************************************************************************************/
/* Prodided port accessors */
/**************************************************************************************************/


/**************************************************************************************************/
/* Private methods */
/**************************************************************************************************/


/**************************************************************************************************/
/* Provided operations */
/**************************************************************************************************/


/**************************************************************************************************/
/* Received events */
/**************************************************************************************************/
