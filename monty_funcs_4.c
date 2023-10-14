#include "monty.h"

void monty_queue(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates the top element of a stack_t linked list to the bottom.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bott;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bott = (*stack)->next;
	while (bott->next != NULL)
		bott = bott->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bott->next = top;
	top->next = NULL;
	top->prev = bott;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the bottom element of a stack_t linked list to the top.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bott;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bott = (*stack)->next;
	while (bott->next != NULL)
		bott = bott->next;

	bott->prev->next = NULL;
	(*stack)->next = bott;
	bott->prev = *stack;
	bott->next = top;
	top->prev = bott;

	(void)line_number;
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
