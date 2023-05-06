#include "coin_state_machine.h"
#include <stdio.h>
#include <time.h>

machineState InsertNickel(void)
{
    return ACCEPTING_COINS;
}   
machineState InsertDime(void)
{
    return ACCEPTING_COINS;
}
machineState SelectItem(void)
{ 
    return DISPENSIN_ITEM;
}
machineState Reset(int* coins_inserted)
{
    *coins_inserted = STARTED_COINS;
    fprintf(stdout,"The machine is rebooting\n");
    fprintf(stdout,"Now the machine is ready\n");
    fprintf(stdout,"Your coins are: %d\n", *coins_inserted);
    return IDLE;
}

machineEvent ask_for_coins(int* coins_inserted)
{
    COINS coin;
    coin.NICKEL = 5;
    coin.DIME = 10;
    char temp = 0;
    while (1)
    {
        printf("Insert coins:\n a) Nickel \n b) Dime \n");
        scanf(" %c", &temp);
        if (temp == 'a')
        {
            *coins_inserted += coin.NICKEL;
            fprintf(stdout, "coins inserted = %d\n", *coins_inserted);
            return EVENT_INSERT_NICKEL;
            break;
        }
        else if (temp == 'b')
        {
            *coins_inserted += coin.DIME;
            fprintf(stdout, "coins inserted = %d\n", *coins_inserted);
            return EVENT_INSERT_DIME;
            break;
        }
        else if (temp == 'r')
        {
            return EVENT_RESET;
        }
        else
        {
            fprintf(stderr, "Error: You inserted a invalid coin, please try again.\n");
        }
    }
}

machineState ask_for_items(int* coins_inserted)
{
    ITEMS item;
    item.CHIPS = 30;
    item.COKE = 25;

    int change = 0;
    char temp = 0;

    while (1)
    {
        fprintf(stdout, "Select a item:\n a) chips (30c)\n b) coke (25c)\n");
        scanf(" %c/n", &temp);
        if (temp == 'a')
        {
            change = *coins_inserted - item.CHIPS;
            if (change < NON_CHANGE)
            {
                fprintf(stderr, "Please insert %d cents more for this product\n", (-1 * change));
                return IDLE;
            }
            fprintf(stdout, "Your change is = %d\n", change);
            return EVENT_SELECT_ITEM;
            break;
        }
        else if (temp == 'b')
        {
            change = *coins_inserted - item.COKE;
            fprintf(stdout, "Your change is = %d\n", change);
            return EVENT_SELECT_ITEM;
            break;
        }
        else if (temp == 'r')
        {
            return EVENT_RESET;
        }
        else
        {
            fprintf(stderr, "Error: You inserted a invalid option, please try again.\n");
        }
    }
}

void delay(int number_of_seconds)
{
    printf("Dispensing");
    int milli_seconds = 1000 * number_of_seconds;
    __clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    {
        printf(".");
    }
    printf("\n");
}

void ask_for_reset(void)
{
    fprintf(stdout, "To reset the system, insert <r> at any time.\n");
}