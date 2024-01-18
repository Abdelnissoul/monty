#include "monty.h"

/**
 * mul_nodes - function that multiple the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: void
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err_handle(8, line_number, "mul");
    }

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - function that modulus the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: void
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err_handle(8, line_number, "mod");
    }

	if ((*stack)->n == 0)
    {
        more_err_handle(9, line_number);
    }
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}