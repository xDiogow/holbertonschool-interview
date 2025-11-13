#include <stdio.h>
#include <stdbool.h>

/**
 * regex_match - Check if a pattern matches a string
 * @str: The string to scan
 * @pattern: The regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	while (*str || *pattern)
	{
		/* Handle '*' */
		if (*(pattern + 1) == '*')
		{
			/* Skip over zero or more of the preceding character */
			if (regex_match(str, pattern + 2))
				return (1);

			/* Match if the first character of str matches pattern[0] */
			while (*str && (*str == *pattern || *pattern == '.'))
			{
				if (regex_match(++str, pattern + 2))
					return (1);
			}
			return (0);
		}
		/* Handle '.' or character match */
		else if (*str && (*str == *pattern || *pattern == '.'))
		{
			++str;
			++pattern;
		}
		else
		{
			return (0); /* Mismatch */
		}
	}

	/* Return true if both strings are fully consumed */
	return (*str == '\0' && *pattern == '\0');
}
