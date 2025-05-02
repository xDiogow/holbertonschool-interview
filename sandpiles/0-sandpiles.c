#include <stdio.h>

#define SIZE 3

void print_grid(int grid[3][3]);

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 1;
	int temp[3][3];

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			grid1[i][j] += grid2[i][j];

	while (unstable)
	{
		unstable = 0;

		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				temp[i][j] = 0;

		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				if (grid1[i][j] > 3)
				{
					unstable = 1;
					temp[i][j] -= 4;
					if (i > 0)
						temp[i - 1][j]++;
					if (i < 2)
						temp[i + 1][j]++;
					if (j > 0)
						temp[i][j - 1]++;
					if (j < 2)
						temp[i][j + 1]++;
				}
			}
		}

		if (unstable)
		{
			printf("=\n");
			print_grid(grid1);
		}

		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				grid1[i][j] += temp[i][j];
	}
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: Grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

