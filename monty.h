#ifndef MONTY_H
#define MONTY_H


/* LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PROTOTYPES */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack);
void set_queue_mode(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void set_stack_mode(stack_t **stack, __attribute__((unused)) unsigned int line_number);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);


#endif /* MONTY_H */