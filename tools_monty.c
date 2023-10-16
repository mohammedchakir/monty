#include "monty.h"


/**
 * open_file - Opens a file.
 * @file_path: The path of the file to open.
 * Return: None.
 */
void open_file(char *file_path)
{
	FILE *filedes = fopen(file_path, "r");

	if (file_path == NULL || finedes == NULL)
		err(2, file_path);

	read_file(finedes);
	fclose(filedes);
}


/**
 * read_file - Reads the contents of a file.
 * @filedes: The pointer to the file descriptor.
 * Return: None.
 */
void read_file(FILE *filedes)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_num = 1; getline(&buffer, &length, filedes) != -1; line_num++)
	{
		format = parse_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * parse_line - Breaks down each line into tokens to determine
 * which function to execute.
 * @buffer: The line from the file.
 * @line_num: The line number.
 * @format: The storage format indicator (0 for stack, 1 for queue).
 * Return: Returns 0 if storage format is set to stack, 1 if it's set to queue.
 */
int parse_line(char *buffer, int line_num, int format)
{
	char *opcode, *val;
	const char *delims = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delims);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delims);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, line_num, format);
	return (format);
}


/**
 * find_func - Determines the appropriate func to execute based on the opcode.
 * @opcode: The opcode.
 * @value: The argument of the opcode.
 * @format: The storage format indicator (0 for stack, 1 for queue).
 * @line_num: The line number.
 * Return: None.
 */
void find_func(char *opcode, char *value, int line_num, int format)
{
	int n;
	int flags;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flags = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, func_list[n].opcode) == 0)
		{
			call_fun(func_list[n].f, opcode, value, line_num, format);
			flags = 0;
		}
	}
	if (flags == 1)
		err(3, line_num, opcode);
}


/**
 * call_fun - Invokes the appropriate function.
 * @func: The pointer to the function to be called.
 * @sop: The string representing the opcode.
 * @value: The string representing a numeric value.
 * @line_num: The line number for the instruction.
 * @format: The storage format specifier (0 for stack, 1 for queue).
 */
void call_fun(op_func func, char *sop, char *value, int line_num, int format)
{
	stack_t *node;
	int flags;
	int n;

	flags = 1;
	if (strcmp(sop, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flags = -1;
		}
		if (value == NULL)
			err(5, line_num);
		for (n = 0; value[n] != '\0'; n++)
		{
			if (isdigit(value[n]) == 0)
				err(5, line_num);
		}
		node = create_node(atoi(value) * flags);
		if (format == 0)
			func(&node, line_num);
		if (format == 1)
			add_to_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
