#include "main.h"

/**
 * _puts - prints a string and a new line
 * @s: string to be printed
 * Return: length of the string
 **/

int _puts(char *s)
{
	char *first = s;

	while (*s)
		_putchar(*s++);
	return (s - first);
}

/**
 * _putchar - print a character
 * @ch: character to be printed
 * Return: 1 if succeeded otherwise -1
 **/

int _putchar(int ch)
{
	static char buffer[LOCAL_BUF];
	static int bytNum;

	if (bytNum >= LOCAL_BUF || ch == CLEAN_BUF)
	{
		write(1, buffer, bytNum);
		bytNum = 0;
	}
	if (ch != CLEAN_BUF)
		buffer[bytNum++] = ch;
	return (1);
}

