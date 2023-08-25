#include "main.h"

/**
 * display_from_to - display range of addresses
 * @begin: beginning address
 * @end: ending address
 * @exclude: excluding address
 * Return: displayed number of bytes
 **/

int display_from_to(char *begin, char *end, char *exclude)
{
	int fts = 0;

	while (begin <= end)
	{
		if (begin != exclude)
			fts += _putchar(*begin);
		begin++;
	}
	return (fts);
}

/**
 * display_rev - display reverse
 * @argptr: argument pointer
 * @prmts: struct parameters
 * Return: displayed number of bytes
 **/

int display_rev(va_list argptr, prmts_t *prmts)
{	
	int length, rts = 0;
	char *ast = va_arg(argptr, char *);
	(void)prmts;

	if (ast)
	{
		for (length = 0; *ast; ast++)
			length++;
		ast--;
		for (; length > 0; length--, ast--)
			rts += _putchar(*ast);
	}
	return (rts);
}

/**
 * display_rot13 - display characters in rot13
 * @argptr: argument pointer
 * @prmts: strunct parameters
 * Return: counter
 **/

int display_rot13(va_list argptr, prmts_t *prmts)
{
	int rr, rt13, inc = 0;
	char ary[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";
	char *ras = va_arg(argptr, char *);
	(void)prmts;

	rr = 0;
	rt13 = 0;
	while (ras[rr])
	{
		if ((ras[rr] >= 'A' && ras[rr] <= 'Z')
				|| (ras[rr] >= 'a' && ras[rr] <= 'z'))
		{
			rt13 = ras[rr] - 65;
			inc += _putchar(ary[rt13]);
		}
		else
			inc += _putchar(ary[rr]);
		rr++;
	}
	return (inc);
}
