#include "monty.h"

/**
 * monty_nop - Performs no operation for the Monty opcode 'nop'.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Prints the character in the top element of a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
