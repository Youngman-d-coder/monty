#include "monty.h"

/**
 * set_stack_mode - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void set_stack_mode(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    (void)line_number;
    (void)stack; /* Unused parameter */

    /* Do nothing, already in stack mode (LIFO) */
}

/**
 * set_queue_mode - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void set_queue_mode(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        stack_t *temp = *stack;
        while (temp->next)
            temp = temp->next;

        (*stack)->prev = temp;
        temp->next = *stack;
        *stack = (*stack)->next;
        (*stack)->prev->next = NULL;
        (*stack)->prev = NULL;
    }
}