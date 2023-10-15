#include "monty.h"


/**
 * open_file - Opens a file.
 * @file_name: The path of the file to open.
 * Return: None.
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - Reads the contents of a file.
 * @fd: Pointer to the file descriptor.
 * Return: None.
 */
void read_file(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_num = 1; getline(&buffer, &length, fd) != -1; line_num++)
	{
		format = parse_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * parse_line - Breaks down each line into tokens to determine
 * which function to execute.
 * @buffer: The line from the file.
 * @line_number: The line number.
 * @format: The storage format indicator (0 for stack, 1 for queue).
 * Return: Returns 0 if storage format is set to stack, 1 if it's set to queue.
 */
int parse_line(char *buffer, int line_number, int format)
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

	find_func(opcode, val, line_number, format);
	return (format);
}


/**
 * find_func - Determines the appropriate func to execute based on the opcode.
 * @opcode: The opcode.
 * @value: The argument of the opcode.
 * @format: The storage format indicator (0 for stack, 1 for queue).
 * @ln: The line number.
 * Return: None.
 */
void find_func(char *opcode, char *value, int ln, int format)
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
			call_fun(func_list[n].f, opcode, value, ln, format);
			flags = 0;
		}
	}
	if (flags == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Invokes the appropriate function.
 * @func: Pointer to the function to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @format: Storage format specifier (0 for stack, 1 for queue).
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flags;
	int n;

	flags = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flags = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (n = 0; val[n] != '\0'; n++)
		{
			if (isdigit(val[n]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flags);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
