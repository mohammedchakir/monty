#include <stdlib.h>


unsigned int _abs(int a);
char *get_int(int num);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - Converts an integer to a character pointer for a new string.
 * @num: The number to convert to a string.
 * Return: Character pointer to newly created string, or NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int tmp;
	int leng = 0;
	long num_l = 0;
	char *reg;

	tmp = _abs(num);
	len = get_numbase_len(tmp, 10);

	if (num < 0 || num_l < 0)
		len++;
	reg = malloc(len + 1);
	if (!reg)
		return (NULL);

	fill_numbase_buff(tmp, 10, reg, len);
	if (num < 0 || num_l < 0)
		reg[0] = '-';

	return (reg);
}

/**
 * _abs - Calculates the absolute value of an integer.
 * @a: The integer to find the absolute value of.
 * Return: An unsigned integer representing the absolute value of i.
 */
unsigned int _abs(int a)
{
	if (a < 0)
		return (-(unsigned int)a);
	return ((unsigned int)a);
}

/**
 * get_numbase_len - Calculates the length of buffer needed for an uns integer.
 * @num: The number to get the length needed for.
 * @base: The base of the number representation used by the buffer.
 * Return: An integer containing the length of the buffer needed.
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int length = 1;

	while (num > base - 1)
	{
		length++;
		num /= base;
	}
	return (length);
}

/**
 * fill_numbase_buff - Fills a buffer with the correct numbers up to base 36.
 * @num: The number to convert to a string using the specified base.
 * @base: The base of the number used in the conversion (up to base 36).
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 * Return: Always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int reb, a = buff_size - 1;

	buff[buff_size] = '\0';
	while (a >= 0)
	{
		reb = num % base;
		if (reb > 9)
			buff[a] = reb + 87;
		else
			buff[i] = reb + '0';
		num /= base;
		a--;
	}
}
