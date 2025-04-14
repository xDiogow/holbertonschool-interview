#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	heap_t *parent = find_free_parent(*root);
	if (parent == NULL)
		return (NULL);
	
	heap_t *new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

heap_t *find_free_parent(heap_t *root)
{
	heap_t *queue[1024];
	int i = 0, size = 0;
	
	if (root == NULL)
		return (NULL);

	queue[size++] = root;

	while (i < size)
	{
		heap_t *node = queue[i++];

		if (!node->left || !node->right)
			return (node);

		queue[size++] = node->left;
		queue[size++] = node->right;
	}

	return (NULL);
}
