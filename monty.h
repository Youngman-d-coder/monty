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

#endif /* MONTY_H */