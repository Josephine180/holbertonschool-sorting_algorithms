#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
*swap - Swap two integers in an array.
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
* partition - Lomuto partition scheme for Quick Sort.
* @array: Array of integers to partition.
* @low: Starting index of the partition.
* @high: Ending index of the partition (pivot).
* @size: Size of the array (for printing).
*
* Return: The final position of the pivot.
*/
size_t partition(int *array, size_t low, size_t high, size_t size)
{
int pivot = array[high];
int j;
int i = low;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
swap(&array[i], &array[j]);
print_array(array, sizeof(array) / sizeof(array[0]));
i++;
}
}
swap(&array[i], &array[high]);
print_array(array, sizeof(array) / sizeof(array[0]));
return (i);
}

/**
* quick_sort_recursive - Recursive Quick Sort implementation.
* @array: Array of integers to sort.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Size of the array (for printing).
*/
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
size_t pivot_index;
if (low < high)
{
pivot_index = partition(array, low, high, size);
if (pivot_index > 0)
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}

