#include "main.h"

/**
 * display_char - display characters
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_char(va_list argptr, prmts_t *prmts)
{
	char did_char = ' ';
	unsigned int did = 1, add = 0, ch = va_arg(argptr, int);

	if (prmts->subtract_f)
		add += _putchar(ch);
	while (did++ < prmts->w)
		add += _putchar(did_char);
	if (!prmts->subtract_f)
		add += _putchar(ch);
	return (add);
}

/**
 * display_int - display numbers
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_int(va_list argptr, prmts_t *prmts)
{
	long li;

	if (prmts->l_modi)
		li = va_arg(argptr, long);
	else if (prmts->h_modi)
		li = (short int)va_arg(argptr, int);
	else
		li = (int)va_arg(argptr, int);
	return (display_digit(change(li, 10, 0, prmts), prmts));
}

/**
 * display_string - display strings
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_string(va_list argptr, prmts_t *prmts)
{
	char *s = va_arg(argptr, char *), did_char = ' ';
	unsigned int did = 0, add = 0, di = 0, dj;

	(void)prmts;
	switch ((int)(!s))
	{
		case 1:
			s = TERMINATING_NULL;
	}

	dj = did = _strlen(s);
	if (prmts->perc < did)
		dj = did = prmts->perc;

	if (prmts->subtract_f)
	{
		if (prmts->perc != UINT_MAX)
			for (di = 0; di < did; di++)
				add += _putchar(*s++);
		else
			add += _puts(s);
	}
	while (dj++ < prmts->w)
		add += _putchar(did_char);
	if (!prmts->subtract_f)
	{
		if (prmts->perc != UINT_MAX)
			for (di = 0; di < did; di++)
				add += _putchar(*s++);
		else
			add += _puts(s);
	}
	return (add);
}

/**
 * display_percent - display percent
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_percent(va_list argptr, prmts_t *prmts)
{
	(void)argptr;
	(void)prmts;
	return (_putchar('%'));
}

/**
 * display_s - custom format specifier
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_s(va_list argptr, prmts_t *prmts)
{
	char *s = va_arg(argptr, char *);
	char *hex;
	int add = 0;

	if ((int)(!s))
		return (_puts(TERMINATING_NULL));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hex = change(*s, 16, 0, prmts);
			if (!hex[1])
				add += _putchar('0');
			add += _puts(hex);
		}
		else
		{
			add += _putchar(*s);
		}
		return (add);
	}
}
