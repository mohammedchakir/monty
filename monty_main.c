#include "monty.h"


/**
 * main - The entry point of the program.
 * @argc: The count of arguments.
 * @argv: The list of arguments.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

