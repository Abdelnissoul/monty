#include "monty.h"

/**
 * print_char - function that prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (stack == NULL || *stack == NULL)
    {
		string_err_handle(11, line_number);
    }
	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
    {
        string_err_handle(10, line_number);
    }
	printf("%c\n", ascii_value);
}

/**
 * print_str - function that prints a string.
 * @stack: Pointer to a pointer pointing to top node.
 * @ln: the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii_value;
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	ptr = *stack;
	while (ptr != NULL)
	{
		ascii_value = ptr->n;
		if (ascii_value <= 0 || ascii_value > 127)
        {
            break;
        }
		printf("%c", ascii_value);
		ptr = ptr->next;
	}
	printf("\n");
}

/**
 * rotleft - function that rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node.
 * @ln: the line number of of the opcode.
 */
void rotleft(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	ptr = *stack;
	while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

	ptr->next = *stack;
	(*stack)->prev = ptr;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotright - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotright(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	ptr = *stack;

	while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

	ptr->next = *stack;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	(*stack)->prev = ptr;
	(*stack) = ptr;
}
