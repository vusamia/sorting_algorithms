#include "sort.h"
#include <stdio.h>

/**
 * swapd_nod - swaps a node with the next node in the list
 * @hd: double pointer to the beginning of the list
 * @nd: node to swap
 *
 * Return: void
 */
void swapd_nod(listint_t **hd, listint_t *nd)
{
	nd->next->prev = nd->prev;
	if (nd->prev)
		nd->prev->next = nd->next;
	else
		*hd = nd->next;
	nd->prev = nd->next;
	nd->next = nd->next->next;
	nd->prev->next = nd;
	if (nd->next)
		nd->next->prev = nd;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swapd = 1;
	listint_t *cy;

	if (list == NULL || *list == NULL)
		return;
	cy = *list;
	while (swapd != 0)
	{
		swapd = 0;
		while (cy->next != NULL)
		{
			if (cy->next->n < cy->n)
			{
				swapd_nod(list, cy);
				swapd = 1;
				print_list(*list);
			}
			else
				cy = cy->next;
		}
		if (swapd == 0)
			break;
		swapd = 0;
		while (cy->prev != NULL)
		{
			if (cy->prev->n > cy->n)
			{
				swapd_nod(list, cy->prev);
				swapd = 1;
				print_list(*list);
			}
			else
				cy = cy->prev;
		}
	}
}
