#ifndef COIN_STATE_MACHINE_H_
#define COIN_STATE_MACHINE_H_

#define TIME_FOR_DISPENSING 1
#define NON_CHANGE 0

#define MIN_COINS_TO_CONTINUE 25
#define STARTED_COINS 0

typedef enum{
    IDLE,
    ACCEPTING_COINS,
    DISPENSIN_ITEM,
}machineState;

typedef enum{
    EVENT_INSERT_NICKEL,
    EVENT_INSERT_DIME,
    EVENT_SELECT_ITEM,
    EVENT_RESET 
}machineEvent;

typedef struct{
    int NICKEL;
    int DIME;
}COINS;

typedef struct{
    int CHIPS;
    int COKE;
}ITEMS;

machineState InsertNickel(void);
machineState InsertDime(void);
machineState SelectItem(void);
machineState Reset(int* coins_inserted);

machineEvent ask_for_coins(int *coins_inserted);
machineState ask_for_items(int *coins_inserted);
void delay(int number_of_seconds);
void ask_for_reset(void);

#endif