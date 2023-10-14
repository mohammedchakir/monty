#include "monty.h"

/**
 * set_op_tok_error - Assigns an error code as the last element in op_toks.
 * @error_code: Integer to be stored as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int tok_len = 0, a = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	tok_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (tok_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (a < tok_len)
	{
		new_toks[a] = op_toks[a];
		a++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[a++] = exit_str;
	new_toks[a] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
