#include "monty.h"



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


/**
 * mul_nodes - Multiplies the values of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer representing the line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Computes the modulo of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_num, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_num);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
