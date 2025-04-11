#include <stdio.h>
#include <stddef.h>
#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Adds a new node at the right position
 * @head: head
 * @number: Value 	
 * Return: new head
 */
listint_t *insert_node(listint_t **head, const int number)
{
	listint_t *new_node, *current = *head, *prev = NULL;
	
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = *head;

	if (*head == NULL || (*head)->n > number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	
	while (current != NULL && current->n < number)
	{
		prev = current;
		current = current->next;
	}
	
	prev->next = new_node;
	new_node->next = current;

	return (new_node);
}
