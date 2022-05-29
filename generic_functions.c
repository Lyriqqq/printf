#include "main.h"

/**
 * _putc - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1
 */

int _putc(char c)
{
	return (write(1, &c, 1));
}

/**
 * *_strcat - concatenates two strings
 * @dest: char that concatenates
 * @src: char to be concatenated
 * Return: pointer
 */

char *_strcat(char *dest, char *src)
{
	int pos_dest, pos_src;

	for (pos_dest = 0; dest[pos_dest] != '\0'; pos_dest++)
	{
	}
	for (pos_src = 0; src[pos_src] != '\0'; pos_src++)
	{
		dest[pos_dest + pos_src] = src[pos_src];
	}
	return (dest);
}

/**
 * clear_buffer - clear the buffer
 * @buffer: pointer to the buffer to clear
 * Return: pointer to the buffer
 */

void clear_buffer(char *buffer)
{
	int pos_b;

	for (pos_b = 0; pos_b < 1023; pos_b++)
	{
		buffer[pos_b] = 0;
	}
}

/**
 * print_buffer - print the buffer
 * @buffer: pointer to the buffer
 * @len: size of the buffer
 */

void print_buffer(char *buffer, int len)
{
	write(1, buffer, len);
}


/**
 * _strlen - Returns the length of a string
 * @s: string to count
 * Return: Size of the string
 */

int _strlen(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; )
	{
		x++;
	}

	return (x);
}
