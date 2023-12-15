#include "sort.h"


listint_t *head_node(listint_t *temp);

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
