#include "main.h"

/**
 * start_parameter - clean struct playground and reset the buffer
 * @argptr: the argument pointer
 * @prmts: the prmts struct
 * Return: void
 **/

void start_parameter(prmts_t *prmts, va_list argptr)
{
	prmts->nosign  = 0;
	prmts->add_f = 0;
	prmts->space_f = 0;
	prmts->hash_f = 0;
	prmts->zero_f = 0;
	prmts->subtract_f = 0;
	prmts->w = 0;
	prmts->perc = UINT_MAX;
	prmts->h_modi = 0;
	prmts->l_modi = 0;
	(void)argptr;
}

