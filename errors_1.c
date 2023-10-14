#include "monty.h"

/**
 * usage_error - Prints error messages related to usage.
 * Return: Always returns (EXIT_FAILURE).
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints error messages related to memory allocation (malloc).
 * Return: Always returns (EXIT_FAILURE).
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints file opening error messages along with the filename.
 * @filename: Name of the file that failed to open.
 * Return: Always returns (EXIT_FAILURE).
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints error messages for unknown instructions.
 * @opcode: The opcode where the error occurred.
 * @line_number: The line number in the Monty bytecodes file where the error occurred.
 * Return: Always returns (EXIT_FAILURE).
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints error messages for invalid monty_push arguments.
 * @line_number: The line number in the Monty bytecodes file where the error occurred.
 * Return: Always returns (EXIT_FAILURE).
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
