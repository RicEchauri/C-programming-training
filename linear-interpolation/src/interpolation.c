#include "interpolation.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int interpolation (int *x_array, int x_len, int *y_array, int y_len, int desired_point)
{
    is_sorted(x_array, x_len);
    y_len = y_len - OFFSET;
    x_len = x_len - OFFSET;
    float slope = ((float)y_array[0] - (float)y_array[y_len]) / ((float)x_array[0] - (float)x_array[x_len]);
    float interpolate_point = y_array[0] + ((x_array[desired_point] - x_array[0]) * slope); 
    return (int)interpolate_point;
}

void merge_sort(int *array, int len)
{
    merge_recurtion(array, INDEX_0, len - 1);
}

void merge_recurtion(int *array, int left_index, int rigth_index)
{
    if (left_index < rigth_index)
    {
        int midle_index = left_index + (rigth_index - left_index) / 2;

        merge_recurtion(array, left_index, midle_index);
        merge_recurtion(array, midle_index + 1, rigth_index);

        merge_sorted(array, left_index, midle_index, rigth_index);
    }
}
void merge_sorted(int *array, int left_index, int midle_index, int rigth_index)
{
    int left_len = midle_index - left_index + 1;
    int rigth_len = rigth_index - midle_index;

    int temp_left[left_len];
    int temp_rigth[rigth_len];

    int idx, idy, idz;

    for(int index = 0; index < left_len; index++)
    {
        temp_left[index] = array[left_index + index]; 
    }
    for(int index = 0; index < rigth_len; index++)
    {
        temp_rigth[index] = array[midle_index + 1 + index];
    }
    
    for(idx = 0, idy = 0, idz = left_index; idz <= rigth_index; idz++)
    {
        if((idx < left_len) && (idy >= rigth_len || temp_left[idx] <= temp_rigth[idy]))
        {
            array[idz] = temp_left[idx];
            idx++;
        }
        else
        {
            array[idz] = temp_rigth[idy];
            idy++;
        }
    }
}

void is_sorted(int *array, int len)
{
    int *temp = malloc(len * sizeof(len));
    if (temp == NULL){
        fprintf(stderr, "Error: Fail in malloc inside of is_sorted");
        exit(1);
    }
    memcpy(temp, array, len * sizeof(len));
    merge_sort(temp, len);

    if (*temp != *array)
    {
        printf("Warnig: The array was unsorted but now it is sorted\n");
        memcpy(array, temp, len * sizeof(len));
    }
    free(temp);
}