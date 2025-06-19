#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int ac, char **av)
{
	int level;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s level\n", av[0]);
		return (EXIT_FAILURE);
	}

	level = atoi(av[1]);
	menger(level);

	return (EXIT_SUCCESS);
}
