#include "main.h"

/**
 * _printf - my printf function
 * @format: format string
 * @...: elipsis dynamic arguments
 * Return: the number of characters printed except '\0'
 **/

int _printf(const char *format, ...)
{
	prmts_t prmts = START_PARAMETER;
	int var = 0;
	char *ptrr, *begin;
	va_list argptr;

	va_start(argptr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptrr = (char *)format; *ptrr; ptrr++)
	{
		start_parameter(&prmts, argptr);
		if (*ptrr != '%')
		{
			var += _putchar(*ptrr);
			continue;
		}
		begin = ptrr;
		ptrr++;
		while (grep_f(ptrr, &prmts))
			ptrr++;
		ptrr = grep_w(ptrr, &prmts, argptr);
		ptrr = grep_perc(ptrr, &prmts, argptr);
		if (grep_modi(ptrr, &prmts))
			ptrr++;
		if (!grep_spec(ptrr))
			var += display_from_to(begin, ptrr,
					prmts.h_modi || prmts.l_modi ? ptrr - 1 : 0);
		else
			var += grep_display_func(ptrr, argptr, &prmts);
	}
	_putchar(CLEAN_BUF);
	va_end(argptr);
	return (var);
}

