#include "monty.h"

/**
 * Description: name of function
 * 
 * @argc: argument constant.
 * @argv: argument variable.
 * 
 * Return: Exit Success
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;

    fclose(file);
    return (EXIT_SUCCESS);
}