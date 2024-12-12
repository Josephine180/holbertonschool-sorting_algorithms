#include "sort.h"

/**
* bubble_sort -  function that sorts an array of
* integers in ascending order using the Bubble sort algorithm
* @array: pointeurs on the array
* @size: size of the array
* Return: nothing
*/

void bubble_sort(int *array, size_t size)
{
size_t i, temp;
int swapped_flag = 0;
int global_flag = 0;
if (size < 2)
return;
while (global_flag == 0)
{
swapped_flag = 0;
for (i = 0; i < size - 1; i++)
{
if (array[i + 1] < array[i])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
print_array(array, size);
swapped_flag = 1;
}
}
if (swapped_flag != 1)
global_flag = 1;
}
}
