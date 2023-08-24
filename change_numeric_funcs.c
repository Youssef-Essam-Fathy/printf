#include "main.h"

/**
 * display_hexa - display lowercase hexadecimal numbers
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_hexa(va_list argptr, prmts_t *prmts)
{
	unsigned long dl;
	int ch = 0;
	char *s;

	if (prmts->l_modi)
		dl = (unsigned long)va_arg(argptr, unsigned long);
	else if (prmts->h_modi)
		dl = (unsigned short int)va_arg(argptr, unsigned int);
	else
		dl = (unsigned int)va_arg(argptr, unsigned int);

	s = change(dl, 16, CHANGE_NOTSIGNED | CHANGE_LOWCASE, prmts);
	if (prmts->hash_f && dl)
	{
		*--s = 'x';
		*--s = '0';
	}
	prmts->nosign = 1;
	return (ch = display_digit(s, prmts));
}

/**
 * display_HEXA - display uppercase hexadecimal numbers
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_HEXA(va_list argptr, prmts_t *prmts)
{
	unsigned long dl;
	int ch = 0;
	char *s;

	if (prmts->l_modi)
		dl = (unsigned long)va_arg(argptr, unsigned long);
	else if (prmts->h_modi)
		dl = (unsigned short int)va_arg(argptr, unsigned int);
	else
		dl = (unsigned int)va_arg(argptr, unsigned int);

	s = change(dl, 16, CHANGE_NOTSIGNED, prmts);
	if (prmts->hash_f && dl)
	{
		*--s = 'X';
		*--s = '0';
	}
	prmts->nosign = 1;
	return (ch = display_digit(s, prmts));
}

/**
 * display_binary - display binary numbers
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_binary(va_list argptr, prmts_t *prmts)
{
	unsigned int bn = va_arg(argptr, unsigned int);
	char *s = change(bn, 2, CHANGE_NOTSIGNED, prmts);
	int ch = 0;

	if (prmts->hash_f && bn)
		*--s = '0';
	prmts->nosign = 1;
	return (ch += display_digit(s, prmts));
}

/**
 * display_octal - display octal numbers
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: integer
 **/

int display_octal(va_list argptr, prmts_t *prmts)
{
	unsigned long dl;
	int ch = 0;
	char *s;

	if (prmts->l_modi)
		dl = (unsigned long)va_arg(argptr, unsigned long);
	else if (prmts->h_modi)
		dl = (unsigned short int)va_arg(argptr, unsigned int);
	else
		dl = (unsigned int)va_arg(argptr, unsigned int);

	s = change(dl, 8, CHANGE_NOTSIGNED, prmts);

	if (prmts->hash_f && dl)
		*--s = '0';
	prmts->nosign = 1;
	return (ch += display_digit(s, prmts));
}
