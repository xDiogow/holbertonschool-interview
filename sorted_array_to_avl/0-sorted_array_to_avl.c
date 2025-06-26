#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index
 * @end: Ending index
 * @parent: Pointer to parent node
 *
 * Return: Pointer to the new node or NULL on failure
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = create_avl(array, start, mid - 1, node);
	node->right = create_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (create_avl(array, 0, (int)size - 1, NULL));
}
