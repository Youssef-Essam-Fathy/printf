#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define LOCAL_BUF 1024
#define CLEAN_BUF -1

#define TERMINATING_NULL "(null)"

#define START_PARAMETER {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CHANGE_LOWCASE 1
#define CHANGE_NOTSIGNED 2

/**
 * struct prmts - Struct parameters
 * @nosign: unsigned value
 * @add_f: plus flag
 * @space_f: space flag
 * @hash_f: hashtag flag
 * @zero_f: zero flag
 * @subtract_f: minus flag
 * @w: width
 * @perc: percision
 * @h_modi: h modifier
 * @l_modi: l modifier
 **/

typedef struct prmts
{
	unsigned int nosign : 1;
	unsigned int add_f : 1; /* + */
	unsigned int space_f : 1; /* ' ' */
	unsigned int hash_f : 1; /* # */
	unsigned int zero_f : 1; /* 0 */
	unsigned int subtract_f : 1; /* - */
	unsigned int w;
	unsigned int perc;
	unsigned int h_modi : 1; /* h */
	unsigned int l_modi : 1; /* l */
} prmts_t;

/**
 * struct spec - Struct specifier
 * @spec: specifier
 * @f: function poiter
 **/

typedef struct spec
{
	char *spec;
	int (*f)(va_list, prmts_t *);
} spec_t;

/* put_func.c */
int _puts(char *s);
int _putchar(int ch);

/* display_funcs.c */
int display_char(va_list argptr, prmts_t *prmts);
int display_int(va_list argptr, prmts_t *prmts);
int display_string(va_list argptr, prmts_t *prmts);
int display_percent(va_list argptr, prmts_t *prmts);
int display_s(va_list argptr, prmts_t *prmts);

/* numeric_func.c */
char *change(long int digit, int ground, int tags, prmts_t *prmts);
int display_notsigned(va_list argptr, prmts_t *prmts);
int display_address(va_list argptr, prmts_t *prmts);

/* spec_funcs.c */
int (*grep_spec(char *sp))(va_list argptr, prmts_t *prmts);
int grep_display_func(char *sp, va_list argptr, prmts_t *prmts);
int grep_f(char *sp, prmts_t *prmts);
int grep_modi(char *sp, prmts_t *prmts);
char *grep_w(char *sp, prmts_t *prmts, va_list argptr);

/* change_numeric_funcs.c */
int display_hexa(va_list argptr, prmts_t *prmts);
int display_HEXA(va_list argptr, prmts_t *prmts);
int display_binary(va_list argptr, prmts_t *prmts);
int display_octal(va_list argptr, prmts_t *prmts);

/* easy_displayer.c */
int display_from_to(char *begin, char *end, char *exclude);
int display_rev(va_list argptr, prmts_t *prmts);
int display_rot13(va_list argptr, prmts_t *prmts);

/* display_digit.c */
int _isNum(int ch);
int _strlen(char *st);
int display_digit(char *s, prmts_t *prmts);
int display_digit_right(char *s, prmts_t *prmts);
int display_digit_left(char *s, prmts_t *prmts);

/* prmts.c */
void start_parameter(prmts_t *prmts, va_list argptr);

/* str_playground.c */
char *grep_perc(char *ptr, prmts_t *prmts, va_list argptr);

/* my_printf_func.c */
int _printf(const char *format, ...);

#endif /* MAIN_FUNC_H */

