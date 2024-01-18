#include "monty.h"

/**
 * err_handle - Prints appropiate error message which dewtermined by the error code.
 * @error_code: the exact error on the code
 * Return : free nodes and exit failure
 */
void err_handle(int error_code, ...)
{
    va_list arg;
    char *op;
    int line_num;

    va_start(arg, error_code);

	if (error_code == 1)
	{
        fprintf(stderr, "USAGE: monty file\n");
    }
	else if (error_code == 2)
	{
        fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
    }
	else if (error_code == 3)
	{
        line_num = va_arg(arg, int);
        op = va_arg(arg, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
    }
	else if (error_code == 4)
	{
        fprintf(stderr, "Error: malloc failed\n");
    }
	else if (error_code == 5)
	{
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
	}
	va_end(arg);

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err_handle - handles errors.
 * @error_code: the exact error on the code
 * Return : free nodes and exit failure
 */
void more_err_handle(int error_code, ...)
{
    va_list arg;
    char *op;
    int line_num;

    va_start(arg, error_code);

    if (error_code == 6)
	{
        fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
    }
	else if (error_code == 7)
	{
        fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arg, int));
    }
	else if (error_code == 8)
	{
        line_num = va_arg(arg, unsigned int);
        op = va_arg(arg, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
    }
	else if (error_code == 9)
	{
        fprintf(stderr, "L%d: division by zero\n", va_arg(arg, unsigned int));
    }
    va_end(arg);

    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * string_err_handle - handles errors.
 * @error_code: the exact error on the code
 * Return : free nodes and exit failure
 */
void string_err_handle(int error_code, ...)
{
    va_list arg;
    int line_num;

    va_start(arg, error_code);
    line_num = va_arg(arg, int);

    if (error_code == 10)
	{
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
    }
	else if (error_code == 11)
	{
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
    }

    va_end(arg);

    free_nodes();
    exit(EXIT_FAILURE);
}
