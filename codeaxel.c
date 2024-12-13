#include "sort.h"

/**
* swap_listint_left - Swaps node of doubly linked list with its previous
* @head: Adress to head of linked list
* @node: Node to swap
* Return: Adress to head of linked list
*/

listint_t   **swap_listint_left(listint_t **head, listint_t *node)
{
    listint_t   *tmp, *node_left;
    // Vérifie si les pointeurs sont valides (liste, tête de liste et nœud à déplacer).
    if (!head || !*head || !node)
        return (NULL);
    // Si le nœud à déplacer est directement après la tête,
    // mettre à jour la tête pour qu'elle pointe sur le nœud en cours.
    if (node->prev == *head)
        *head = node;
    // Sauvegarde le suivant de `node` et le prédécesseur immédiat dans des variables temporaires.
    tmp = node->next;
    node_left = node->prev;
    // Si le prédécesseur de `node_left` existe,
    // on met à jour son suivant pour qu'il pointe vers `node`.
    if (node->prev->prev)
        node->prev->prev->next = node;
    // Si le nœud courant a un suivant,
    // met à jour son pointeur précédent pour qu'il pointe vers `node_left`.
    if (node->next)
        node->next->prev = node->prev;
    // Mise à jour des liens du nœud courant (`node`) pour le déplacer :
    // - Son suivant devient son prédécesseur.
    // - Son prédécesseur devient le prédécesseur de `node_left`.
    node->next = node->prev;
    node->prev = node->prev->prev;
    // Mise à jour des liens de l'ancien prédécesseur (`node_left`) :
    // - Son prédécesseur devient le nœud courant (`node`).
    // - Son suivant devient le nœud temporaire initialement sauvegardé (`tmp`).
    node_left->prev = node;
    node_left->next = tmp;
    // Affiche l'état de la liste après le déplacement.
    print_list(*head);
    // Retourne l'adresse de la tête de la liste.
    return (head);
}
/**
* insertion_sort_list - Sorts doubly linked list using Insertion Sort
* @list: Adress to head of linked list
*/
void    insertion_sort_list(listint_t **list)
{
    listint_t *iter_a, *iter_b;
    // Vérifie si la liste est vide, contient un seul élément,
    // ou si le pointeur vers la tête est invalide. Dans ces cas, on ne fait rien.
    if (!list || !*list || !(*list)->next)
        return;
    // Initialise `iter_a` pour parcourir la liste à partir du premier élément.
    iter_a = *list;
    // Parcours de tous les éléments de la liste.
    while (iter_a)
    {
        // Pour chaque élément pointé par `iter_a`, on initialise `iter_b` au même nœud.
        iter_b = iter_a;
        // Boucle interne pour déplacer `iter_b` vers la gauche jusqu'à ce qu'il soit à sa place.
        // - Vérifie que `iter_b` a un prédécesseur (sinon, rien à échanger).
        // - Vérifie que la valeur de `iter_b` est inférieure à celle de son prédécesseur.
        while (iter_b && iter_b->prev && iter_b->n < iter_b->prev->n)
        {
            // Appelle `swap_listint_left` pour échanger `iter_b` et son prédécesseur.
            swap_listint_left(list, iter_b);
        }
        // Avance `iter_a` au nœud suivant pour traiter le prochain élément.
        iter_a = iter_a->next;
    }
}
