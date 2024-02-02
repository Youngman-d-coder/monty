#include "monty.h"

/**
 * add - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void add(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;
  if (!stack || !*stack || !((*stack)->next))
  {
    fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  (*stack)->next->n += (*stack)->n;

  temp = *stack;
  *stack = (*stack)->next;

  free(temp);
  (*stack)->prev = NULL;
}

/**
 * sub - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void sub(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (!stack || !*stack || !((*stack)->next))
  {
    fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  (*stack)->next->n -= (*stack)->n;

  temp = *stack;
  *stack = (*stack)->next;

  free(temp);
  (*stack)->prev = NULL;
}

/**
 * divide - name of function
 *you 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void divide(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (!stack || !*stack || !((*stack)->next))
  {
    fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  if ((*stack)->n == 0)
  {
    fprintf(stderr, "L%u: division by zero\n", line_number);
    exit(EXIT_FAILURE);
  }

  (*stack)->next->n /= (*stack)->n;

  temp = *stack;
  *stack = (*stack)->next;

  free(temp);
  (*stack)->prev = NULL;
}

/**
 * multiply - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void multiply(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (!stack || !*stack || !((*stack)->next))
  {
    fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  (*stack)->next->n *= (*stack)->n;

  temp = *stack;
  *stack = (*stack)->next;

  free(temp);
  (*stack)->prev = NULL;
}

/**
 * modulo - name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
void modulo(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (!stack || !*stack || !((*stack)->next))
  {
    fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  if ((*stack)->n == 0)
  {
    fprintf(stderr, "L%u: division by zero\n", line_number);
    exit(EXIT_FAILURE);
  }

  (*stack)->next->n %= (*stack)->n;

  temp = *stack;
  *stack = (*stack)->next;

  free(temp);
  (*stack)->prev = NULL;
}