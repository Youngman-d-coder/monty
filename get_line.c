#include "monty.h"

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufferSize = 128;
	size_t currentPosition = 0;
	int curren = tChar;

	if (*lineptr == NULL)
		*n = 0;

	while (1)
	{
		currentChar = fgetc(stream);

		if (currentChar == EOF || currentChar == '\n')
		{
		  (*lineptr)[currentPosition] = '\0';
		  return (currentPosition == 0 && currentChar == EOF ? -1 : currentPosition);
		}

		(*lineptr)[currentPosition] = (char)currentChar;
		currentPosition++;

		if (currentPosition >= bufferSize - 1)
		{
		  bufferSize *= 2;

		  *lineptr = realloc(*lineptr, bufferSize);

		  if (*lineptr == NULL)
		  {
		    perror("Error reallocating memory");
				exit(EXIT_FAILURE);
			}
		}
	}
}