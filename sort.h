#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t   **swap_listint_left(listint_t **head, listint_t *node);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, int size);
void swap(int *a, int *b);
int partition(int *array, int low, int high, int size);
void quick_sort_recursive(int *array, int low, int high, int size);
#endif
