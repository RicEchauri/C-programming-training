/*
### State machine:
Problem Statement: Coin State Machine
- You are tasked with implementing a state machine for a coin-operated vending machine.
  The vending machine accepts only two types of coins: nickel (5 cents) and dime (10 cents),
  and has three possible states: IDLE, ACCEPTING_COINS, and DISPENSING_ITEM.
  The vending machine dispenses only one item, which costs 25 cents.
  The state machine should handle the following events:
    EVENT_INSERT_NICKEL: Represents the insertion of a nickel coin.
    EVENT_INSERT_DIME: Represents the insertion of a dime coin.
    EVENT_SELECT_ITEM: Represents the selection of an item.
    EVENT_RESET: Represents a reset event.

- The state machine should have the following behavior:
    - In the IDLE state, if a nickel or a dime is inserted (EVENT_INSERT_NICKEL or EVENT_INSERT_DIME),
      transition to the ACCEPTING_COINS state and update the amount of inserted coins accordingly.
    - In the IDLE state, if the item is selected (EVENT_SELECT_ITEM) and the amount of inserted
      coins is equal to or greater than 25 cents, transition to the DISPENSING_ITEM state and
      dispense the item. If the amount of inserted coins is less than 25 cents, stay in the
      IDLE state and do not dispense the item.
    - In the ACCEPTING_COINS state, if a nickel or a dime is inserted, update the amount of
      inserted coins accordingly.
    - In the ACCEPTING_COINS state, if the item is selected and the amount of inserted coins
      is equal to or greater than 25 cents, transition to the DISPENSING_ITEM state and dispense
      the item. If the amount of inserted coins is less than 25 cents, stay in the ACCEPTING_COINS
      state and do not dispense the item.
    - In the DISPENSING_ITEM state, dispense the item for 1 second and then transition back to the
      IDLE state.
    - In any state, if a reset event (EVENT_RESET) is received, transition back to the IDLE state
      and reset the amount of inserted coins.

Your task is to implement the state machine for the coin-operated vending machine in C.
You should provide the following:

    A C header file (coin_state_machine.h) that defines the state machine's states, events,
    and function prototypes for initializing the state machine and handling events.

    A C source file (coin_state_machine.c) that implements the state machine's behavior,
    including the state transition logic and the corresponding actions for each state and event.

    A C main file (main.c) that demonstrates the usage of the state machine,
    including the initialization of the state machine, handling of events, and verification
    of the state transitions and actions.

Note: You are allowed to use any C standard library functions or macros that are available
on an embedded system.

Constraints:
    The state machine should be implemented using a modular and maintainable approach,
    with separate functions for each state and event handling.

    The state machine should handle invalid or unexpected events gracefully,
    without crashing or entering into an undefined state.

    The state machine should be able to handle multiple events in quick succession without
    blocking or freezing.

    The state machine should be efficient in terms of memory usage and execution time,
    as it will run on an embedded system with limited resources.

Evaluation Criteria:
    Your solution will be evaluated based on the following criteria:
        Correctness of the state machine's behavior, including the correct handling of states,
        events, transitions, and actions as per the problem statement.

        Modularity and maintainability of the code, including
*/

#include "coin_state_machine.h"

int main(int argc, char *argv[])
{

    int coins = 0;

    machineState Nextstate = IDLE;
    machineEvent Newevent;
    ask_for_reset();
    while (1)
    {
        switch (Nextstate)
        {
        case IDLE:
        {
            Newevent = ask_for_coins(&coins);

            if (EVENT_RESET == Newevent)
            {
                Nextstate = Reset(&coins);
            }
            if (EVENT_INSERT_NICKEL == Newevent)
            {
                Nextstate = InsertNickel();
            }
            if (EVENT_INSERT_DIME == Newevent)
            {
                Nextstate = InsertDime();
            }
                }
        break;
        case ACCEPTING_COINS:
        {
            if (coins >= MIN_COINS_TO_CONTINUE)
            {
                Newevent = ask_for_items(&coins);
            }
            else
            {
                Nextstate = IDLE;
            }
            if (IDLE == Newevent)
            {
                Nextstate = IDLE;
            }
            if (EVENT_RESET == Newevent)
            {
                Nextstate = Reset(&coins);
            }
            if (EVENT_SELECT_ITEM == Newevent)
            {
                Nextstate = SelectItem();
            }
        }
        break;
        case DISPENSIN_ITEM:
        {
            delay(TIME_FOR_DISPENSING);
            coins = 0;
            Nextstate = IDLE;
        }
        break;
        default:
            break;
        }
    }

    return 0;
}