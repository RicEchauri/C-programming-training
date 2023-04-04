#include "interpolation.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int x_array[] = {10,18,0,6,8,2,12,14,16,4};
    //int x_array[] = {0,1,2,3,4,5,6,7,8,9};
    int y_array[] = {0,4,8,12,16,20,24,28,32,36};

    int x_len = sizeof(x_array)/sizeof(x_array[0]);
    int y_len = sizeof(y_array)/sizeof(y_array[0]);

    int point_to_interpolate = 6;

    int y_desired = interpolation(x_array, x_len, y_array, y_len, point_to_interpolate);
    printf("Your desired point by linear interpolation is: %d\n", y_desired);

    return 0;
}