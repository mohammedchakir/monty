#include <stdlib.h>


/**
 * strtow - Splits a string into individual words using delimiters.
 * @str: The string to be split into words.
 * @delims: Delimiters used to separate words.
 * Return: A 2D array of pointers, with each pointer pointing to an individual word.
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - Checks if a character in a stream is a delimiter.
 * @ch: The character to check in the stream.
 * @delims: Pointer to a null-terminated array of delimiters.
 * Return: 1 (success) if the character is a delimiter, 0 (failure) otherwise.
 */
int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Retrieves the length of the current word in a string.
 * @str: The string from which to get the word length of the current word.
 * @delims: Delimiters used to separate words.
 * Return: The length of the current word.
 */
int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - Counts the number of words in a string.
 * @str: The string from which to count words.
 * @delims: Delimiters used to separate words.
 * Return: The word count in the string.
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - Retrieves the next word in a string.
 * @str: The string to extract the next word from.
 * @delims: Delimiters used to separate words.
 * Return: A pointer to the first character of the next word.
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
