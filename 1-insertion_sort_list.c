#include "sort.h"


listint_t *head_node(listint_t *temp);

/**
 *insertion_sort_list - Function that sorts a doubly linked list of integers
 *                       using inssertion sorting algorithm
 *
 *@list: The doubly linked list
 *
 *Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *hold;
	listint_t *pre_t;


	if (list == NULL)
		return;

	temp = head_node(*list);

	for (temp = temp->next; temp;)
	{
		hold = temp->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			pre_t = temp->prev;
			pre_t->next = temp->next;
			temp->prev = pre_t->prev;
			pre_t->prev = temp;
			temp->next = pre_t;
			if (pre_t->next)
				pre_t->next->prev = pre_t;
			if (temp->prev)
				temp->prev->next = temp;
			print_list(head_node(*list));
		}
		temp = hold;
	}
	*list = head_node(*list);
}


/**
 *head_node - Function that gets the head of a
 *             doubly linked list
 *
 *@temp: node in linked list
 *
 *Return: head of linked list
 */

listint_t *head_node(listint_t *temp)
{
	while (temp->prev)
		temp = temp->prev;

	return (temp);
}
