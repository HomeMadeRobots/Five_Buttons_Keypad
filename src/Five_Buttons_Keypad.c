#include "Five_Buttons_Keypad.h"


/*============================================================================*/
/* Types, Macros */
/*============================================================================*/
typedef enum { KEYPAD_PRESSED, KEYPAD_RELEASED } E_Keypad_State;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Five_Buttons_Keypad__Cyclic( const Five_Buttons_Keypad* Me )
{
    T_Voltage pin_voltage = 0;
    static E_Keypad_State keypad_state = KEYPAD_RELEASED;
    static E_Button_Id last_button_pressed = NO_BUTTON;
    E_Button_Id current_button_pressed = NO_BUTTON;
    

    /* Get the curent pressed button */
    Me->Analog_Pin->Get_Voltage( &pin_voltage );

    if( pin_voltage > Me->No_Button_Threshold )
    {
        current_button_pressed = NO_BUTTON;
    }
    else if(    pin_voltage <= Me->No_Button_Threshold 
             && pin_voltage >  Me->Select_Button_Threshold )
    {
        current_button_pressed = SELECT_BUTTON;
    }
    else if(    pin_voltage <= Me->Select_Button_Threshold
             && pin_voltage >  Me->Left_Button_Threshold )
    {
        current_button_pressed = LEFT_BUTTON;
    }
    else if(    pin_voltage <= Me->Left_Button_Threshold 
             && pin_voltage >  Me->Down_Button_Threshold )
    {
        current_button_pressed = DOWN_BUTTON;
    }
    else if(    pin_voltage <= Me->Down_Button_Threshold
             && pin_voltage >  Me->Up_Button_Threshold )
    {
        current_button_pressed = UP_BUTTON;
    }
    else if( pin_voltage <= Me->Up_Button_Threshold )
    {
        current_button_pressed = RIGHT_BUTTON;
    }

    if( keypad_state == KEYPAD_RELEASED )
    {
        if( current_button_pressed != NO_BUTTON )
        {
            if( last_button_pressed == current_button_pressed )
            {
                switch( current_button_pressed )
                {
                    case SELECT_BUTTON :
                        Me->Select_Button_Pressed();
                        break;
                    case UP_BUTTON :
                        Me->Up_Button_Pressed();
                        break;
                    case DOWN_BUTTON :
                        Me->Down_Button_Pressed();
                        break;
                    case LEFT_BUTTON :
                        Me->Left_Button_Pressed();
                        break;
                    case RIGHT_BUTTON :
                        Me->Right_Button_Pressed();
                        break;
                    default :
                        break;
                }
                Me->Any_Button_Pressed( current_button_pressed );
  
                keypad_state = KEYPAD_PRESSED;
            }
        }
        else
        { /* current_button_pressed == NO_BUTTON */
            /* keypad remains in KEYPAD_RELEASED state */
        }
    }
    else
    { /* keypad_state = PRESSED */
        if(    last_button_pressed == NO_BUTTON 
            && current_button_pressed == NO_BUTTON )
        {
            keypad_state = KEYPAD_RELEASED;
        }
    }
    last_button_pressed = current_button_pressed;
}