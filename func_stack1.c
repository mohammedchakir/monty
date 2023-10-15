#include "monty.h"


/**
 * add_to_stack - Pushes a node into the stack.
 * @new_node: The pointer to the new node.
 * @ln: An integer showing the line number of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * print_stack - Displays the contents of a stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}



/**
 * pop_top - Removes and returns the top node from the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_number: An integer showing the line number of the opcode.
 */

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}


/**
 * print_top - Displays the value of the top node of the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_number: An integer showing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
