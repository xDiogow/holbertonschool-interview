#include "sort.h"

/**
 * merge_top_down - sorts an array using top dow merge sort algorithm.
 * @array: the array to sort
 * @output: copy of array
 * @l: left index of the sub-array
 * @m: middle index of the sub-array
 * @r: right index of the sub-array + 1
 *
 * Return: Nothing
 */
void merge_top_down(int *array, int *output, int l, int m, int r)
{
	int i = l, j = m, k = 0;

	while (i < m && j < r)
	{
		if (array[i] < array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < m)
	{
		output[k] = array[i];
		i++;
		k++;
	}
	while (j < r)
	{
		output[k] = array[j];
		j++;
		k++;
	}
	i = l;
	k = 0;
	while (i < r)
	{
		array[i] = output[k];
		i++;
		k++;
	}
}

/**
 * print_infos_merge_sort - prints a formatted output.
 * @array: the array to sort
 * @output: copy of array
 * @l: left index of the sub-array
 * @m: middle index of the sub-array
 * @r: right index of the sub-array + 1
 *
 * Return: Nothing
 */
void print_infos_merge_sort(int *array, int *output, int l, int m, int r)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + m, r - m);

	merge_top_down(array, output, l, m, r);

	printf("[Done]: ");
	print_array(array + l, r - l);
}

/**
 * merge - recursively sorts an array in ascending order.
 * @array: the array to sort
 * @output: copy of array
 * @l: left index of the sub-array
 * @r: right index of the sub-array + 1
 *
 * Return: Nothing
 */
void merge(int *array, int *output, int l, int r)
{
	int m;

	if (r - l > 1)
	{
		m = l + (r - l) / 2;
		merge(array, output, l, m);
		merge(array, output, m, r);
		print_infos_merge_sort(array, output, l, m, r);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the merge sort algorithm.
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *output;

	if (size < 2)
		return;

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	merge(array, output,  0, size);

	free(output);
}
