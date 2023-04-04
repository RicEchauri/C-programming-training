#ifndef SENDER_H_
#define SENDER_H_

#define NUM_OF_DATA 100
#define MAX_BATTERY_LEVEL 100
#define MIN_BATTERY_LEVEL 0
#define MAX_STATE_OF_CHARGE_LEVEL 255
#define MIN_STATE_OF_CHARGE_LEVEL 0
#define OFFSET 1
#define DECREASE 2
#define CHANGE_OF_DATA '@'


int Battery_level(char interactions);
int State_of_charge(void);
void sendData(void);

#endif