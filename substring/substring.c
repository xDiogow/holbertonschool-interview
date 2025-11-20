#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * count_word_occurrences - Count the occurrences of each word in `words`.
 * @words: The array of words to count.
 * @nb_words: The number of words in the array.
 * @word_count: The array to store the occurrence counts.
 */
void count_word_occurrences(char const **words, int nb_words, int *word_count)
{
	for (int i = 0; i < nb_words; i++)
	{
		word_count[i] = 0;
		for (int j = 0; j < nb_words; j++)
			if (strcmp(words[i], words[j]) == 0)
				word_count[i]++;
	}
}

/**
 * find_word_in_words - Finds a word in the array `words`.
 * @word: The word to search for.
 * @words: The array of words.
 * @nb_words: The number of words in the array.
 * Return: The index of the word in `words`, or -1 if not found.
 */
int find_word_in_words(char const *word, char const **words, int nb_words)
{
	for (int i = 0; i < nb_words; i++)
	{
		if (strcmp(word, words[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * sliding_window_search - Perform the sliding window search over string `s`.
 * @s: The string to search within.
 * @words: The array of words to concatenate.
 * @nb_words: The number of words in the array.
 * @substring_len: The total length of the concatenated words.
 * @word_count: The array of word occurrences.
 * @indices: The array to store the starting indices of found substrings.
 * @n: A pointer to store the number of found indices.
 */
void sliding_window_search(char const *s, char const **words, int nb_words,
						   int substring_len, int *word_count, int *indices,
						    int *n)
{
	int word_len = strlen(words[0]);
	int s_len = strlen(s);
	int *current_count = malloc(nb_words * sizeof(int));

	if (!current_count)
		return;

	for (int i = 0; i <= s_len - substring_len; i++)
	{
		memset(current_count, 0, nb_words * sizeof(int));
		int j;

		for (j = 0; j < nb_words; j++)
		{
			char temp[word_len + 1];

			strncpy(temp, s + i + j * word_len, word_len);
			temp[word_len] = '\0';

			int index = find_word_in_words(temp, words, nb_words);

			if (index == -1 || ++current_count[index] > word_count[index])
				break;
		}

		if (j == nb_words)
			indices[(*n)++] = i;
	}

	free(current_count);
}

/**
 * find_substring - Finds all starting indices of substrings formed by
 * concatenation of all words in `words` within the string `s`.
 * @s: The string to search within.
 * @words: The array of words to concatenate.
 * @nb_words: The number of words in the array.
 * @n: A pointer to store the number of found indices.
 * Return: An allocated array containing the starting indices of valid
 * substrings, or NULL if no valid substring is found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len = strlen(s);
	int word_len = strlen(words[0]);
	int substring_len = word_len * nb_words;

	if (!s || !words || nb_words == 0 || !n || s_len < substring_len)
	{
		*n = 0;
		return (NULL);
	}

	int *word_count = calloc(nb_words, sizeof(int));
	int *indices = malloc((s_len - substring_len + 1) * sizeof(int));

	if (!word_count || !indices)
		return (NULL);

	count_word_occurrences(words, nb_words, word_count);
	*n = 0;

	sliding_window_search(s, words, nb_words, substring_len, word_count,
							 indices, n);

	free(word_count);

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}

	return (indices);
}
