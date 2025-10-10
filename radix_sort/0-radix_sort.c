#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_max - Get the maximum value in an array
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: Maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Sort array using counting sort for radix sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Current exponent (power of 10)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	/* Count occurrences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/** Change count[i] so that count[i] now contains actual*/
	/* position of this digit in output[]*/

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array to array[], so that array[] now*/
	/* contains sorted numbers according to current digit */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers using Radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	/* Find the maximum number to know number of digits */
	max = get_max(array, size);

	/* Do counting sort for every digit. Note that instead*/
	/* of passing digit number, exp is passed. exp is 10^i*/
	/* where i is current digit number*/
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
