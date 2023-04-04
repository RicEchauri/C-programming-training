#ifndef INTERPOLATION_H_
#define INTERPOLATION_H_

#define OFFSET 1
#define INDEX_0 0
int interpolation (int *x_array, int x_len, int *y_array, int y_len, int desired_point);
void merge_sort(int *array, int len);
void merge_recurtion(int *array, int left_index, int rigth_index);
void merge_sorted(int *array, int left_index,int midle_index, int rigth_index);
void is_sorted(int *array, int len);

#endif