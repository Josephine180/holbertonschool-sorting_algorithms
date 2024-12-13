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
/* temp variable temporaire utilisée pour échanger deux élts du tableau */
/* idx_temp a l'indice du plus petit élt trouvé lors de la recherche*/
size_t j, i;
/* variables utilisées pour les boucles*/
for (i = 0; i < size - 1; i++)
/* boucle qui parcourt le tableau de gauche à droite */
/* a chaque itération */
{
idx_temp = i;
for (j = i + 1; j < size; j++)
/* j démarre à i + 1 (après i) et compare les elt non triés*/
{
if (array[j] < array[idx_temp])
/* array[j](elt indice j) est plus petit que array[idx_temp] */
/* elt considéré comme le plus petit */
{
idx_temp = j;
/*on met à jour idx_temp pour qu'il pointe vers j, l'indice du nouvel elt */
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
