#ifendef MONTY_H
#define MONTY_H


/* LIBRARIES*/
#include <stdio.h>
#include <stlib.h>
#include <string.h>

/* STRUCTURES */
typedef struct stack_s
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PROTOTYPES */
void push(stack_t **stack, int value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
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
void print_str(stack_t **stack, unsigned int line_number);
void set_queue_mode(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void set_stack_mode(stack_t **stack, __attribute__((unused)) unsigned int line_number);


#endif /* MONTY_H */