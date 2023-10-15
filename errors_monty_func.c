#include "monty.h"


/**
 * err - Displays the appropriate error message based on the error code.
 * @err_code: The error codes and their meanings are as follows:
 * (1) => No file provided or more than one file given to the program.
 * (2) => The provided file cannot be opened or read.
 * (3) => The file contains an invalid instruction.
 * (4) => Unable to allocate more memory (malloc failed).
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The "pint" instruction was called on an empty stack.
 * (7) => The "pop" instruction was called on an empty stack.
 * (8) => The stack does not have enough elements for the operation.
 */
void err(int err_code, ...)
{
	va_list arg;
	char *oper;
	int line_num;

	va_start(arg, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			line_num = va_arg(arg, int);
			oper = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, oper);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * more_err - Manages and handles specific error cases.
 * @err_code: The error codes and their meanings are as follows:
 * (6) => Attempted "pint" on an empty stack.
 * (7) => Attempted "pop" on an empty stack.
 * (8) => Stack does not have enough elements for the operation.
 * (9) => Division by zero error.
 */
void more_err(int err_code, ...)
{
	va_list arg;
	char *oper;
	int line_num;

	va_start(arg, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			line_num = va_arg(arg, unsigned int);
			oper = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, oper);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Manages and handles specific string-related errors.
 * @err_code: The error codes and their meanings are as follows:
 * (10) ~> The number inside node is outside bounds of valid ASCII characters.
 * (11) ~> The stack is empty.
 */
void string_err(int err_code, ...)
{
	va_list arg;
	int line_num;

	va_start(arg, err_code);
	line_num = va_arg(arg, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
