#include "sort.h"

/**
* selection_sort - sorts an array of integers in
* ascending order using the Selection sort algorithm
* @array: pointeur on an array
* @size: size of the array
* Return: nothing
*/


void selection_sort(int *array, size_t size)
{
size_t temp, idx_temp;
size_t j, i;
for (i = 0; i < size - 1; i++)
{
idx_temp = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[idx_temp])
{
idx_temp = j;
}
}
if (idx_temp != i)
{
temp = array[i];
array[i] = array[idx_temp];
array[idx_temp] = temp;
print_array(array, size);
}
}
}
