#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Pointer to array of integers
 * @size: Number of elements in array
 */
void slide_left(int *line, size_t size)
{
	size_t i, pos = 0;
	int last = 0;
	int tmp[32] = {0};

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		if (last == 0)
		{
			last = line[i];
		}
		else if (last == line[i])
		{
			tmp[pos++] = last * 2;
			last = 0;
		}
		else
		{
			tmp[pos++] = last;
			last = line[i];
		}
	}
	if (last != 0)
		tmp[pos++] = last;
	for (i = 0; i < size; i++)
		line[i] = tmp[i];
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Pointer to array of integers
 * @size: Number of elements in array
 */
void slide_right(int *line, size_t size)
{
	ssize_t i, pos = size - 1;
	int last = 0;
	int tmp[32] = {0};

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;
		if (last == 0)
		{
			last = line[i];
		}
		else if (last == line[i])
		{
			tmp[pos--] = last * 2;
			last = 0;
		}
		else
		{
			tmp[pos--] = last;
			last = line[i];
		}
	}
	if (last != 0)
		tmp[pos--] = last;
	for (i = 0; i < (ssize_t)size; i++)
		line[i] = tmp[i];
}

/**
 * slide_line - Slides and merges an array of integers left or right
 * @line: Pointer to array of integers
 * @size: Number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}
