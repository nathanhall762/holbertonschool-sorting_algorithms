#include "sort.h"

void swap(listint_t **head, listint_t **list)
{
	listint_t *b = *head, *a = (*head)->next;

	b->next = a->next;
	a->next = b;
	a->prev = b->prev;
	b->prev = a;
	if (a->prev != NULL)
	{
		a->prev->next = a;
	}
	if (b->next != NULL)
	{
		b->next->prev = b;
	}
	*head = a;
	if (a->prev == NULL)
	{
		*list = a;
	}
}

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list, *back_node;

	if (node == NULL)
		return;
	for (; node->next != NULL; node = node->next)
	{
		if (node->n > node->next->n)
		{
			swap(&node, list);
			print_list(*list);
			back_node = node->prev;
			for (; back_node != NULL; back_node = back_node->prev)
			{
				if (back_node->n > back_node->next->n)
				{
					swap(&back_node, list);
					print_list(*list);
				}
				else
					break;
			}
		}
	}
}
