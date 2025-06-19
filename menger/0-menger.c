#include <stdio.h>
#include "menger.h"


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

void menger(int level)
{
	int size = 1;
	int i, y, x;
	
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
