#include "monty.h"

/**
 * push - adds element at the end of the stack
 * @stack: pointer to the end of the stack
 * @l_number: line number of the error
 * Return: nothing
 */
void push(stack_t **stack, unsigned int l_number)
{
	sttack_t *new_node, *end_node;

	if (mem.n == NULL || check_number(mem.n) == 0)
	{
		_free(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", l_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		_free(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(mem.n);
	if (mem.mode == STACK || (*stack) == NULL)
	{
		new_node->prev = NULL;
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		end_node = *stack;

		while (end_node->next != NULL)
			end_node = end_node->next;
		end_node->next = new_node;
		new_node->prev = end_node;
		new_node->next = NULL;
	}
}
