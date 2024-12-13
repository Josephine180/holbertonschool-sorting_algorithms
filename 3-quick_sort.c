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
* quick_sort_helper - Recursively sorts the array using Quick Sort with Lomuto partition scheme.
*
* @array: The array to be sorted.
* @low: The starting index of the partition.
* @high: The ending index of the partition.
*/
void quick_sort_helper(int *array, int low, int high)
{
if (low < high)
{
int pivot_index = partition(array, low, high);
/* Recursively sort the two partitions */
quick_sort_helper(array, low, pivot_index - 1);
quick_sort_helper(array, pivot_index + 1, high);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick Sort algorithm with the Lomuto partition scheme.
* @array: The array to be sorted.
* @size: Number of elements in the array.
*/
void quick_sort(int *array, size_t size)
{
quick_sort_helper(array, 0, size - 1);
}
