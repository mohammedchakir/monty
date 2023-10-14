#include "monty.h"


/**
 * monty_add - Adds the top two elements of a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: The result is stored in the second element from the top, 
                and the top element is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Subtracts the top element from the second element 
              of a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 * Description: The result is stored in the second element from the top, 
                and the top element is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the second element from the top of a stack_t linked list 
               by the top element.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 * Description: The result is stored in the second element from the top, 
                and the top element is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplies the second element from the top of a stack_t linked list 
               by the top element.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 * Description: The result is stored in the second element from the top, 
                and the top element is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Computes the modulus of the second element from the top 
               of a stack_t linked list by the top element.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 * Description: The result is stored in the second element from the top, 
                and the top element is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
