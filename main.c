#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @ac: arguments count
 * @av: arguments vector
 * Return: always 0
 */
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(av[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - function that creates a node.
 * @n: Number.
 * Return: if success a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		err_handle(4);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - function that frees nodes in the stack.
 * it frees the stack from all data
 */
void free_nodes(void)
{
	stack_t *ptr;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *ptr;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = *new_node;
	(*new_node)->prev = ptr;
}
