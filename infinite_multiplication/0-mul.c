#include "mul.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error_and_exit();
	}

	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
	{
		print_error_and_exit();
	}

	multiply(argv[1], argv[2]);

	return (0);
}

/**
 * print_error_and_exit - prints "Error" and exits with status 98
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit_str - checks if a string is composed of only digits
 * @str: the string to check
 *
 * Return: 1 if true, 0 if false
 */
int is_digit_str(const char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * multiply - multiplies two numbers and prints the result
 * @num1: the first number as a string
 * @num2: the second number as a string
 */
void multiply(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	int i, j, prod, carry;

	if (result == NULL)
	{
		print_error_and_exit();
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
			carry = prod / 10;
			result[i + j + 1] = prod % 10;
		}
		result[i + j + 1] += carry;
	}

	print_result(result, len1 + len2);

	free(result);
}

/**
 * print_result - prints the result of the multiplication
 * @result: the array containing the result
 * @size: the size of the result array
 */
void print_result(int *result, int size)
{
	int i = 0;

	while (i < size && result[i] == 0)
	{
		i++;
	}
	if (i == size)
	{
		_putchar('0');
	}
	for (; i < size; i++)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');
}
