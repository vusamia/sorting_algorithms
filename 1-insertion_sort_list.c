#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swp_nod, *nxt_swp;

	if (list == NULL || *list == NULL)
		return;
	swp_nod = (*list)->next;
	while (swp_nod != NULL)
	{
		nxt_swp = swp_nod->next;
		while (swp_nod->prev != NULL && swp_nod->prev->n > swp_nod->n)
		{
			swp_nod->prev->next = swp_nod->next;
			if (swp_nod->next != NULL)
				swp_nod->next->prev = swp_nod->prev;
			swp_nod->next = swp_nod->prev;
			swp_nod->prev = swp_nod->next->prev;
			swp_nod->next->prev = swp_nod;
			if (swp_nod->prev == NULL)
				*list = swp_nod;
			else
				swp_nod->prev->next = swp_nod;
			print_list(*list);
		}
		swp_nod = nxt_swp;
	}
}
