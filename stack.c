#include "monty.h"
#include <string.h>

/**
 * free_stack - Deallocates memory used by a stack_t.
 * @stack: A pointer to the top (for stack) or bottom (for queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes a stack_t data structure with both stack and queue features.
 * @stack: A pointer to an uninitialized stack_t structure.
 * Return: On success - EXIT_SUCCESS, On failure - EXIT_FAILURE.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks the mode of a stack_t linked list (stack or queue).
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t linked list.
 * Return: If the stack_t is in stack mode - STACK (0).
           If the stack_t is in queue mode - QUEUE (1).
	   Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
