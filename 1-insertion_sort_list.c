#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || *list == (*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		tmp = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			listint_t *prev = current->prev;

			if (current->next)
				current->next->prev = prev;
			prev->next = current->next;

			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;

			print_list(*list);
		}
		current = tmp;
	}
}
