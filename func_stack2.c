#include "monty.h"


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
 * sub_nodes - Subtracts the values of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_num, "sub");


	(*stack) = (*stack)->next;
	total = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Divides the values of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "div");

	if ((*stack)->n == 0)
		more_err(9, line_num);
	(*stack) = (*stack)->next;
	total = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
