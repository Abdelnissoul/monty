#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack or queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 * Description: doubly linked list node structure LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_func)(stack_t **stack, unsigned int line_number);
/*functions that treats files*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*functions that handles stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
/*Different operations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);
/*operations with strings*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
/*Error hanlding from the code*/
void err_handle(int error_code, ...);
void more_err_handle(int error_code, ...);
void string_err_handle(int error_code, ...);
void rotright(stack_t **, unsigned int);
void rotleft(stack_t **, unsigned int);

#endif
