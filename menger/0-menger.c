#include <stdio.h>
#include "menger.h"

/**
 * is_hole - Determines if a position in the Menger sponge is a hole
 * @x: The x coordinate
 * @y: The y coordinate
 *
 * Return: 1 if the position is a hole, 0 otherwise
 */
int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: The level of the sponge
 */
void menger(int level)
{
	int size = 1;
	int i, y, x;

	if (level < 0)
		return;

	for (i = 0; i < level; i++)
		size *= 3;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_hole(x, y))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}

