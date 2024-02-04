#include "monty.h"
#include <stdio.h>
int is_integer(const char *str)
{
	char *endptr;
	strtol(str, &endptr, 10);

		    /* Check if the entire string was parsed (no conversion errors) */
	return (*endptr == '\0');
}
/**
 * process_line - Tokenizes and processes a line of the Monty script.
 *
 * @line: Line from the Monty script.
 * @stack: Pointer to the stack.
 * @line_number: Line number being processed.
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode, *operand;
    int value;

    opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
    {
        return;  /* Ignore empty lines and comments */
    }

    operand = strtok(NULL, " \t\n");
    if (operand != NULL)
    {
        value = atoi(operand);
    }

    if (strcmp(opcode, "push") == 0)
    {
        if (operand == NULL || !is_integer(operand))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        push(stack, value);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
        nop(stack, line_number);
    }else if (strcmp(opcode, "sub") == 0)
    {
        sub(stack, line_number);
    }
    else if (strcmp(opcode, "mul") == 0)
    {
        multiply(stack, line_number);
    }
    else if (strcmp(opcode, "div") == 0)
    {
        divide(stack, line_number);
    }
    else if (strcmp(opcode, "mod") == 0)
    {
        modulo(stack, line_number);
    }
    else if (strcmp(opcode, "pchar") == 0)
    {
        print_char(stack, line_number);
    }
    else if (strcmp(opcode, "pstr") == 0)
    {
        print_str(stack);
    }
    else if (strcmp(opcode, "rotr") == 0)
    {
        rotate_right(stack, line_number);
    }
    else if (strcmp(opcode, "rotl") == 0)
    {
        rotate_left(stack, line_number);
    }
    else if (strcmp(opcode, "stack") == 0)
    {
        set_stack_mode(stack, line_number);
    }
    else if (strcmp(opcode, "queue") == 0)
    {
        set_queue_mode(stack, line_number);
    } 
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

/**
 * monty_interpreter - Executes Monty script.
 *
 * @file: Pointer to the Monty script file.
 * @stack: Pointer to the stack.
 */
void monty_interpreter(FILE *file, stack_t **stack)
{
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        process_line(line, stack, line_number);
    }

    free(line);
}

/**
 * main - Entry point of the Monty interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */ 
int main(int argc, char *argv[])
{
  stack_t *stack;
  FILE *file;

  if (argc != 2)
  {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
  }

  file = fopen(argv[1], "r");
  if (!file)
  {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  stack = NULL;

  monty_interpreter(file, &stack);

  fclose(file);
  return (EXIT_SUCCESS);
}
