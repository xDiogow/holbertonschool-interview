#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	int stack[2048], index = -1;

	if (*head == NULL)
		return (1);

	while (fast && fast->next)
	{
		stack[++index] = slow->n;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
		slow = slow->next;

	while (slow)
	{
		if (stack[index--] != slow->n)
			return (0);
		slow = slow->next;
	}

	return (1);
}
