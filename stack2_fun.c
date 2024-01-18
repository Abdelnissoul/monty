#include "monty.h"

/**
 * nop - Void function that Does nothing.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: the line number of of the opcode.
 * Return: Void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - function that swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err_handle(8, line_number, "swap");
    }
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	if (ptr->next != NULL)
    {
        ptr->next->prev = *stack;
    }
	ptr->next = *stack;
	(*stack)->prev = ptr;
	ptr->prev = NULL;
	*stack = ptr;
}

/**
 * add_nodes - function that adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err_handle(8, line_number, "add");
    }
	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - function that substract the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		more_err_handle(8, line_number, "sub");
    }

	(*stack) = (*stack)->next;
	add = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - function that divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err_handle(8, line_number, "div");
    }

	if ((*stack)->n == 0)
    {
        more_err_handle(9, line_number);
    }
	(*stack) = (*stack)->next;
	add = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}