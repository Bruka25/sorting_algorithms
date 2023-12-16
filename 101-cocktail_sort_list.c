#include "sort.h"



/**
 *cocktail_sort_list - Sort a listint_t doubly-linked list 
 *                     using the cocktail shaker algorithm
 *
 *@list: Pointer to the head of a listint_t doubly-linked list
 *
 *Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *cock_shaker;
	bool not_shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (not_shaken == false)
	{
		not_shaken = true;
		for (cock_shaker = *list; cock_shaker != tail; 
				cock_shaker = cock_shaker->next)
		{
			if (cock_shaker->n > cock_shaker->next->n)
			{
				swap_node_next(list, &tail, &cock_shaker);
				print_list((const listint_t *)*list);
				not_shaken = false;
			}
		}
		for (cock_shaker = cock_shaker->prev; cock_shaker != *list;
				cock_shaker = cock_shaker->prev)
		{
			if (cock_shaker->n < cock_shaker->prev->n)
			{
				swap_node_prev(list, &tail, &cock_shaker);
				print_list((const listint_t *)*list);
				not_shaken = false;
			}
		}
	}
}


/**
 *swap_node_next - Function that swaps a node in a listint_t doubly-linked
 *                 list with the node ahead of it
 *
 *@list: Pointer to the head of a doubly-linked list of integers
 *@tail: Pointer to the tail of the doubly-linked list
 *@cock_shaker: Pointer to the current swapping node of the cocktail shaker
 *              algorithm
 *
 *Return: Void
 */

void swap_node_next(listint_t **list, listint_t **tail, listint_t **cock_shaker)
{
	listint_t *temp = (*cock_shaker)->next;

	if ((*cock_shaker)->prev != NULL)
		(*cock_shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*cock_shaker)->prev;
	(*cock_shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *cock_shaker;
	else
		*tail = *cock_shaker;
	(*cock_shaker)->prev = temp;
	temp->next = *cock_shaker;
	*cock_shaker = temp;
}

/**
 *swap_node_prev - Function that Swaps a node in a listint_t doubly-linked
 *                 list with the node behind it
 *
 *@list: Pointer to the head of a doubly-linked list of integers
 *@tail: Pointer to the tail of the doubly-linked list
 *@cock_shaker: Pointer to the current swapping node of
 *              the cocktail shaker algorithm
 *
 *Return: Void
 */

void swap_node_prev(listint_t **list, listint_t **tail, listint_t **cock_shaker)
{
	listint_t *temp = (*cock_shaker)->prev;

	if ((*cock_shaker)->next != NULL)
		(*cock_shaker)->next->prev = temp;
	else
	 	*tail = temp;
	temp->next = (*cock_shaker)->next;
	(*cock_shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *cock_shaker;
	else
		*list = *cock_shaker;
	(*cock_shaker)->next = temp;
	temp->prev = *cock_shaker;
	*cock_shaker = temp;
}
