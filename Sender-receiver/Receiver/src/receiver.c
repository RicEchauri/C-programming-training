#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "receiver.h"



void getData( int *Data_A, int *Data_B )
{
    for (char index_of_data = 0; index_of_data < NUM_OF_DATA; index_of_data++)
    {
        char *line = NULL;
        size_t len = 0;
        size_t lineSize = 0;
        lineSize = getline(&line, &len, stdin);
        char *faile_parse;

        if ( lineSize == -1 )
        {
            fprintf(stderr, "Error: Fail on getline inside of getdata\n");
            exit(EXIT_FAILURE);
        }

        lineSize = lineSize - OFFSET;

        char *divide_in_ptr = strchr(line, CHANGE_OF_DATA);
        if ( divide_in_ptr == NULL )
        {
            fprintf(stderr,"Warning: I can not found the change character\n");
            //exit(EXIT_FAILURE);
        }

        size_t size_of_A = divide_in_ptr - line;
        size_t size_of_B = lineSize - size_of_A;

        char *first_data = malloc(size_of_A * sizeof(int));
        if (!first_data)
        {
            fprintf(stderr, "Error:Fail in malloc first_data\n");
            exit(EXIT_FAILURE);
        }

        char *second_data = malloc(size_of_B * sizeof(int));
        if (!second_data)
        {
            fprintf(stderr, "Error:Fail in malloc second_data\n");
            exit(EXIT_FAILURE);
        }

        memcpy(first_data, line, size_of_A * sizeof(int));
        memcpy(second_data, line + size_of_A + SIZE_OF_CHANGE_CHARATCTER, size_of_B * sizeof(int));
        
        Data_A[index_of_data] = strtol(first_data, &faile_parse, 10);
        if ( first_data == faile_parse)
        {
            fprintf(stderr, "Error:Fail parse in first data\n");
            exit(EXIT_FAILURE);
        }

        Data_B[index_of_data] = strtol(second_data, &faile_parse, 10);
        if ( second_data == faile_parse)
        {
            fprintf(stderr, "Error:Fail parse in second data\n");
            exit(EXIT_FAILURE);
        }

        free( first_data );
        free( second_data );
    }
}

void print_all_Data( int *Data_A, int *Data_B )
{
    for (char index_of_data = 0; index_of_data < NUM_OF_DATA; index_of_data++)
    {
        printf("Signal_A= %d    Signal_B= %d\n", Data_A[index_of_data], Data_B[index_of_data]);
    }
}

int get_min(int *data)
{
    int min = data[0];
    for (char index_of_data = 0; index_of_data < NUM_OF_DATA; index_of_data++)
    {
        if (data[index_of_data] < min)
        {
            min = data[index_of_data];
        }
    }
    return min;
}
int get_max(int *data)
{
    int max = data[0];
    for (char index_of_data = 0; index_of_data < NUM_OF_DATA; index_of_data++)
    {
        if (data[index_of_data] > max)
        {
            max = data[index_of_data];
        }
    }
    return max;
}

int get_SMA(int *Data)
{
    int sum=0;

    for(int index_of_data=(NUM_OF_DATA - INTERACTIONS); index_of_data<NUM_OF_DATA; index_of_data++)
    {
        sum = sum + Data[index_of_data];
    }
    return(sum/INTERACTIONS);
}