#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sender.h"

int Battery_level( char interactions )
{   
    int porcent_of_battery = MAX_BATTERY_LEVEL - (DECREASE * interactions);
    return porcent_of_battery;
}
int State_of_charge(void)
{
    return(MIN_STATE_OF_CHARGE_LEVEL + rand() % ( MAX_STATE_OF_CHARGE_LEVEL - MIN_STATE_OF_CHARGE_LEVEL + OFFSET ));
}
void sendData(void)
{
    srand( time(NULL) );
    for ( int data_sent = 0; data_sent < NUM_OF_DATA; data_sent++ )
    {
        int signal_sensor_A = Battery_level( data_sent );
        int signal_sensor_B = State_of_charge();
        fprintf( stdout, "%d", signal_sensor_A );
        putchar( CHANGE_OF_DATA );
        fprintf( stdout, "%d\n", signal_sensor_B );
    }  
}