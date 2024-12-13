#include "sort.h"

/**
* swap - Swap two integers in an array.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

/**
* partition - Simplified Lomuto partition for Quick Sort.
* @array: The array to partition.
* @low: The start index of the partition.
* @high: The end index of the partition (pivot).
* @size: Total size of the array (for printing).
* Return: The final position of the pivot.
*/
int partition(int *array, int low, int high, int size)
{
int k;
int j;
int pivot = array[high];
int i = low;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
swap(&array[i], &array[j]);
i++;
}
}
swap(&array[i], &array[high]);
for (k = 0; k < size; k++)
printf("%d%s", array[k], k < size - 1 ? ", " : "\n");
return (i);
}
/**
* quick_sort_recursive - Recursive function for Quick Sort.
* @array: The array to sort.
* @low: The start index of the current partition.
* @high: The end index of the current partition.
* @size: Total size of the array (for printing).
*/
void quick_sort_recursive(int *array, int low, int high, int size)
{
int pivot_index;
if (low < high)
{
pivot_index = partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}
/**
* quick_sort - Main Quick Sort function.
* @array: The array to sort.
* @size: Total size of the array.
*/
void quick_sort(int *array, int size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}
