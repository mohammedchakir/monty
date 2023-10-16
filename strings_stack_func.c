#include "monty.h"


/**
 * print_char - Displays the ASCII value of the top element in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_num)
{
	int val;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_num);

	val = (*stack)->n;
	if (val < 0 || val > 127)
		string_err(10, line_num);
	printf("%c\n", val);
}

/**
 * print_str - Outputs a string from the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int val;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		val = temp->n;
		if (val <= 0 || val > 127)
			break;
		printf("%c", val);
		temp = temp->next;
	}
	printf("\n");
}


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
 * rotl - Shifts the top node of the stack to the bottom.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Moves the bottom node of the stack to the top.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @line_num: An integer showing the line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
