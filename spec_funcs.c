#include "main.h"

/**
 * grep_spec - grep specifier
 * @sp: string pointer
 * return: byte numbers printed
 **/

int (*grep_spec(char *sp))(va_list argptr, prmts_t *prmts)
{
	spec_t specs[] = {
		{"c", display_char},
		{"d", display_int},
		{"i", display_int},
		{"s", display_string},
		{"%", display_percent},
		{"b", display_binary},
		{"o", display_octal},
		{"u", display_notsigned},
		{"x", display_hexa},
		{"X", display_HEXA},
		{"p", display_address},
		{"S", display_s},
		{"r", display_rev},
		{"R", display_rot13},
		{NULL, NULL},
	};
	int ind = 0;

	while (specs[ind].spec)
	{
		if (*sp == specs[ind].spec[0])
		{
			return (specs[ind].f);
		}
		ind++;
	}
	return (NULL);
}

/**
 * grep_display_func - grep display function
 * @sp: string pointer
 * @argptr: argument pointer
 * @prmts: struct Parameters
 * Return: printed bytes number
 **/

int grep_display_func(char *sp, va_list argptr, prmts_t *prmts)
{
	int (*f)(va_list, prmts_t *) = grep_spec(sp);

	if (f)
		return (f(argptr, prmts));
	return (0);
}

/**
 * grep_f -grep flag
 * @sp: dtring pointer
 * @prmts: struct parameters
 * Return: flag
 **/

int grep_f(char *sp, prmts_t *prmts)
{
	int ind = 0;

	switch (*sp)
	{
		case '+':
			ind = prmts->add_f = 1;
			break;
		case ' ':
			ind = prmts->space_f = 1;
			break;
		case '#':
			ind = prmts->hash_f = 1;
			break;
		case '-':
			ind = prmts->subtract_f = 1;
			break;
		case '0':
			ind = prmts->zero_f = 1;
			break;
	}
	return (ind);
}

/**
 * grep_modi -grep modifier
 * @sp: string pointer
 * @prmts: struct parameters
 * Return: modifier
 **/

int grep_modi(char *sp, prmts_t *prmts)
{
	int ind = 0;

	switch (*sp)
	{
		case 'l':
			ind = prmts->l_modi = 1;
			break;
		case 'h':
			ind = prmts->h_modi = 1;
			break;
	}
	return (ind);
}

/**
 * grep_w - grep width function
 * @sp: string pointer
 * @prmts: struct parameters
 * @argptr: argument pointer
 * Return: new pointer
 **/

char *grep_w(char *sp, prmts_t *prmts, va_list argptr)
{
	int wd = 0;

	if (*sp == '*')
	{
		wd = va_arg(argptr, int);
		sp++;
	}
	else
	{
		while (_isNum(*sp))
			wd *= 10 + (*sp++ - '0');
	}
	prmts->w = wd;
	return (sp);
}
