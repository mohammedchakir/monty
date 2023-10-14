#include "monty.h"
#include <string.h>

/**
 * free_tokens - Deallocates memory for the global op_toks string array.
 */
void free_tokens(void)
{
	size_t a = 0;

	if (op_toks == NULL)
		return;

	for (a = 0; op_toks[a]; a++)
		free(op_toks[a]);

	free(op_toks);
}

/**
 * token_arr_len - Calculates the length of the current op_toks array.
 * Return: The length of the current op_toks as an integer.
 */
unsigned int token_arr_len(void)
{
	unsigned int tok_len = 0;

	while (op_tok[tok_len])
		tok_len++;
	return (tok_len);
}

/**
 * is_empty_line - Checks if a line read from getline consists solely of delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 * Return: 1 if the line only contains delimiters, 0 otherwise.
 */
int is_empty_line(char *line, char *delims)
{
	int a, b;

	for (a = 0; line[a]; a++)
	{
		for (b = 0; delims[b]; b++)
		{
			if (line[a] == delims[b])
				break;
		}
		if (delims[b] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its associated function.
 * @opcode: The opcode to match.
 * Return: A pointer to the associated function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int a;

	for (a = 0; op_funcs[a].opcode; a++)
	{
		if (strcmp(opcode, op_funcs[a].opcode) == 0)
			return (op_funcs[a].f);
	}

	return (NULL);
}

/**
 * run_monty - Executes a Monty bytecode script.
 * @script_fd: File descriptor for an open Monty bytecode script.
 * Return: EXIT_SUCCESS on success, the corresponding error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
