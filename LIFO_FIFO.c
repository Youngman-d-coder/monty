#include "monty.h"

/**
 * pall -name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
 void pall(stack_t **stack, unsigned int line_number)
 {
   stack_t *current = *stack;
   
   while (current)
   {
     printf("%d\n", current->n);
     current = current->next;
   }
 }
 
 /**
 * push -name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
 void push(stack_t **stack, int value, unsigned int line_number)
 {
   stack_t *new_node = malloc(sizeof(stack_t));
   if (!new_node)
   {
     fprintf(stderr, "Error: malloc failed\n");
     exit(EXIT_FAILURE);
   }
   new_node->n = value;
   new_node->prev = NULL;
   if (*stack)
   {
     new_node->next = *stack;
     (*stack)->prev = new_node;
   }
   else
   {
     new_node->next = NULL;
   }
   *stack = new_node;
 }
 
 /**
 * pall -name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
 void pint(stack_t **stack, unsigned int line_number)
 {
   if (!stack || !*stack)
   {
     fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
     exit(EXIT_FAILURE);
   }
   printf("%d\n", (*stack)->n);
 }
 
 /**
 * pall -name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
 void pop(stack_t **stack, unsigned int line_number)
 {
   if (!stack || !*stack)
   {
     fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
     exit(EXIT_FAILURE);
   }
   stack_t *temp = *stack;
   if (temp->next)
   {
     *stack = temp->next;
     temp->next->prev = NULL;
   }
   else
   {
     *stack = NULL;
   }
   free(temp);
 }
 
 /**
 * pall -name of function
 * 
 * @stack: stack worked on.
 * @line_number: number of the line.
 * 
 * Return: none
 */
 void swap(stack_t **stack, unsigned int line_number)
 {
   if (!stack || !*stack || ((*stack)->next))
   {
     fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
   }
   stack_t *temp = (*stack)->next;
   if (temp->next)
   {
     (*stack)->next = temp->next;
     temp->next->prev = *stack;
   }
   else
   {
     (*stack)->next = NULL;
   }
   temp->prev = NULL;
   temp->next = *;stack;
   (*stack)->prev = temp;
   *stack = temp;
 }