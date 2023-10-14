#include <stdlib.h>

int get_word_count(char *str, char *delims);
int is_delim(char ch, char *delims);
char **strtow(char *str, char *delims);
int get_word_length(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Splits a string into individual words using delimiters.
 * @str: The string to be split into words.
 * @delims: Delimiters used to separate words.
 * Return: 2D array of pointers, with each ptr pointing to an individual word.
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int ws, wrdLen, b, a = 0;

	if (str == NULL || !*str)
		return (NULL);
	ws = get_word_count(str, delims);


	if (ws == 0)
		return (NULL);
	words = malloc((ws + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (a < ws)
	{
		wrdLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[a] = malloc((wrdLen + 1) * sizeof(char));
		if (words[a] == NULL)
		{
			while (a >= 0)
			{
				a--;
				free(words[a]);
			}
			free(words);
			return (NULL);
		}
		b = 0;
		while (b < wrdLen)
		{
			words[i][b] = *(str + b);
			b++;
		}
		words[a][b] = '\0';
		str = get_next_word(str, delims);
		a++;
	}
	words[a] = NULL;
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
	int a = 0;

	while (delims[a])
	{
		if (delims[a] == ch)
			return (1);
		a++;
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
	int wLen = 0, pend = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			pend = 1;
		else if (pend)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[a], delims))
			break;
		a++;
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
	int ws = 0, pend = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			pend = 1;
		else if (pend)
		{
			pend = 0;
			ws++;
		}
		a++;
	}
	return (ws);
}

/**
 * get_next_word - Retrieves the next word in a string.
 * @str: The string to extract the next word from.
 * @delims: Delimiters used to separate words.
 * Return: A pointer to the first character of the next word.
 */
char *get_next_word(char *str, char *delims)
{
	int pend = 0;
	int a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			pend = 1;
		else if (pend)
			break;
		a++;
	}
	return (str + a);
}
