#include "monty.h"

/**
 * nop - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number; 
    /* To silence any "unused parameter" warnings */
}

/**
 * print_char -name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void print_char(stack_t **stack, unsigned int line_number)
{
  int ascii_value;
  stack_t *temp;

  if (!stack || !*stack)
  {
    fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
    exit(EXIT_FAILURE);
  }

  ascii_value = (*stack)->n;

  if (ascii_value < 0 || ascii_value > 127)
  {
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    exit(EXIT_FAILURE);
  }

  putchar(ascii_value);
  putchar('\n');

    /* Pop the top element of the stack */
  temp = *stack;
  *stack = (*stack)->next;
  free(temp);

  if (*stack)
    (*stack)->prev = NULL;
}

/**
 * print_str - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void print_str(stack_t **stack)
{
    stack_t *temp = *stack;

    while (temp && temp->n != 0 && temp->n >= 0 && temp->n <= 127)
    {
        putchar(temp->n);
        temp = temp->next;
    }

    putchar('\n');

    /* Remove elements of the printed string from the stack */
    while (*stack && (*stack)->n != 0 && (*stack)->n >= 0 && (*stack)->n <= 127)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);

        if (*stack)
            (*stack)->prev = NULL;
    }
}

/**
 * rotate_left - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        stack_t *first = *stack;
        stack_t *second = (*stack)->next;

        while (first->next)
        {
            first = first->next;
        }

        first->next = *stack;
        (*stack)->prev = first;
        (*stack)->next = NULL;

        *stack = second;
        (*stack)->prev = NULL;
    }
}

/**
 * rotate_right - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        stack_t *last = *stack;

        while (last->next)
        {
            last = last->next;
        }

        last->prev->next = NULL;
        last->prev = NULL;
        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
    }
}