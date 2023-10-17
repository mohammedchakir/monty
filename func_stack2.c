#include "monty.h"



/**
 * create_node - Creates a node.
 * @num: The number to store in the node.
 * Return: A pointer to the node on success, or NULL on failure.
 */
stack_t *create_node(int num)
{
	stack_t *vertex;

	vertex = malloc(sizeof(stack_t));
	if (vertex == NULL)
		err(4);
	vertex->next = NULL;
	vertex->prev = NULL;
	vertex->n = num;
	return (vertex);
}


/**
 * free_nodes - Deallocates memory for nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * swap_nodes - Exchanges the positions of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}


/**
 * add_nodes - Adds the values of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nop - Performs no operation.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


