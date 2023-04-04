#ifndef RECEIVER_H_
#define RECEIVER_H_

#define NUM_OF_DATA 50
#define INTERACTIONS 5
#define CHANGE_OF_DATA '@'
#define OFFSET 2
#define SIZE_OF_CHANGE_CHARATCTER 1
#define EXIT_FAILURE 1

#pragma pack(1)

typedef struct
{   
    int data_received[NUM_OF_DATA];
    int max;
    int min;
    int SMA;

}Data;

void getData( int *Data_A, int *Data_B );
void print_all_Data( int *Data_A, int *Data_B );
int get_SMA( int *Data );
int get_min( int *data );
int get_max( int *data );   

#endif