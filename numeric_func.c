#include "main.h"

/**
 * change - changer function act as itoa
 * @digit: integer
 * @ground: base of integer
 * @tags: flags
 * @prmts: struct parameters
 * Return: a string
 **/

char *change(long int digit, int ground, int tags, prmts_t *prmts)
{
	char *csr;
	static char buf[50];
	char signal = 0;
	static char *ary;
	unsigned long int cd = digit;
	(void) prmts;

	if (!(tags & CHANGE_NOTSIGNED) && digit < 0)
	{
		cd = -digit;
		signal = '-';
	}
	ary = tags & CHANGE_LOWCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	csr = &buf[49];
	*csr = '\0';

	do {
		*--csr = ary[cd % ground];
		cd /= ground;
	} while (cd != 0);

	if (signal)
		*--csr = signal;
	return (csr);
}

/**
 * display_notsigned - display unsigned characters
 * @argptr: argument pointers
 * @prmts: struct parameters
 * Return: displayed bytes
 **/

int display_notsigned(va_list argptr, prmts_t *prmts)
{
	unsigned long int dns;

	if (prmts->h_modi)
		dns = (unsigned short int)va_arg(argptr, unsigned int);
	else if (prmts->l_modi)
		dns = (unsigned long)va_arg(argptr, unsigned long);
	else
		dns = (unsigned int)va_arg(argptr, unsigned int);
	prmts->nosign = 1;
	return (display_digit(change(1, 10, CHANGE_NOTSIGNED, prmts), prmts));
}

/**
 * display_address - handles p specifier
 * @argptr: argument pointer
 * @prmts: struct pointer
 * Return: a function
 **/

int display_address(va_list argptr, prmts_t *prmts)
{
	unsigned long int addr = va_arg(argptr, unsigned long int);
	char *dsr;

	if (!addr)
		return (_puts("(nil)"));

	dsr = change(addr, 16, CHANGE_NOTSIGNED | CHANGE_LOWCASE, prmts);
	*--dsr = 'x';
	*--dsr = '0';
	return (display_digit(dsr, prmts));
}
