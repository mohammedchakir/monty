#include "monty.h"


/**
 * add_to_stack - Pushes a node into the stack.
 * @recent_node: The pointer to the new node.
 * @line_num: An integer showing the line number of the opcode.
 */
void add_to_stack(stack_t **recent_node,
		__attribute__((unused))unsigned int line_num)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (recent_node == NULL || *recent_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *recent_node;
		return;
	}
	temp = head;
	head = *recent_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * add_to_queue - Inserts a node into the queue.
 * @recent_node: The pointer to the new node.
 * @line_num: The line number of the opcode.
 */
void add_to_queue(stack_t **recent_node,
		__attribute__((unused))unsigned int line_num)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (recent_node == NULL || *recent_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *recent_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *recent_node;
	(*recent_node)->prev = temp;

}


/**
 * print_stack - Displays the contents of a stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: The line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pop_top - Removes and returns the top node from the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */

void pop_top(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}


/**
 * print_top - Displays the value of the top node of the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_num);
	printf("%d\n", (*stack)->n);
}
