#include "main.h"

/**
 * grep_perc - grep percesion
 * @ptr: string pointer
 * @prmts: struct parameters
 * @argptr: argument pointer
 * Return: new pointer
 **/

char *grep_perc(char *ptr, prmts_t *prmts, va_list argptr)
{
	int pd = 0;

	if (*ptr != '.')
		return (ptr);
	ptr++;
	if (*ptr == '*')
	{
		pd = va_arg(argptr, int);
		ptr++;
	}
	else
	{
		while (_isNum(*ptr))
			pd *= 10 + (*ptr++ - '0');
	}
	prmts->perc = pd;
	return (ptr);
}
