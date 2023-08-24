#include "main.h"

/**
 * _isNum - return digits
 * @ch: character
 * Return: 1 if number, 0 if not
 **/
int _isNum(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns the length of the string
 * @st: string
 * Return: length of the atring
 **/

int _strlen(char *st)
{
	int sli = 0;

	while (*st++)
		sli++;
	return (sli);
}

/**
 * display_digit - display digits
 * @s: string
 * @prmts: struct parameters
 * Return: chars printed
 **/

int display_digit(char *s, prmts_t *prmts)
{
	unsigned int di = _strlen(s);
	int negve = (!prmts->nosign && *s == '-');

	if (!prmts->perc && *s == '0' && !s[1])
		s = "";
	if (negve)
	{
		s++;
		di--;
	}
	if (prmts->perc != UINT_MAX)
		while (di++ < prmts->perc)
			*--s = '0';
	if (negve)
		*--s = '-';
	if (!prmts->subtract_f)
		return (display_digit_right(s, prmts));
	else
		return (display_digit_left(s, prmts));
}

/**
 * display_digit_right - display digits right
 * @s: string
 * @prmts: structure parameters
 * Return: positive or negative integer at right
 **/

int display_digit_right(char *s, prmts_t *prmts)
{
	unsigned int drn = 0, negve, negve2, ddi = _strlen(s);
	char did_char = ' ';

	if (prmts->zero_f && !prmts->subtract_f)
		did_char = '0';
	negve = negve2 = (!prmts->nosign && *s == '-');
	if (negve && ddi < prmts->w && did_char == '0' && !prmts->subtract_f)
		s++;
	else
		negve = 0;
	if ((prmts->add_f && !negve2) ||
			(!prmts->add_f && prmts->space_f && !negve2))
		ddi++;
	if (negve && did_char == '0')
		drn += _putchar('-');
	if (prmts->add_f && !negve2 && did_char == '0' && !prmts->nosign)
		drn += _putchar('+');
	else if (!prmts->add_f && prmts->space_f && !negve2 &&
			!prmts->nosign && prmts->zero_f)
		drn += _putchar(' ');
	while (ddi++ < prmts->w)
		drn += _putchar(did_char);
	if (negve && did_char == ' ')
		drn += _putchar('-');
	if (prmts->add_f && !negve2 && did_char == ' ' && !prmts->nosign)
		drn += _putchar('+');
	else if (!prmts->add_f && prmts->space_f && !negve2 &&
			!prmts->nosign && !prmts->zero_f)
		drn += _putchar(' ');
	drn += _puts(s);
	return (drn);
}

/**
 * display_digit_left - display digits left
 * @s: string
 * @prmts: structure parameters
 * Return: positive or negative integer at left
 **/

int display_digit_left(char *s, prmts_t *prmts)
{
	unsigned int drn = 0, negve, negve2, ddi = _strlen(s);
	char did_char = ' ';

	if (prmts->zero_f && !prmts->subtract_f)
		did_char = '0';
	negve = negve2 = (!prmts->nosign && *s == '-');

	if (negve && ddi < prmts->w && did_char == '0' && !prmts->subtract_f)
		s++;
	else
		negve = 0;
	if (prmts->add_f && !negve2 && !prmts->nosign)
		drn += _putchar('+'), ddi++;
	else if (prmts->space_f && !negve2 && !prmts->nosign)
		drn += _putchar(' '), ddi++;
	drn += _puts(s);
	while (ddi++ < prmts->w)
		drn += _putchar(did_char);
	return (drn);
}
