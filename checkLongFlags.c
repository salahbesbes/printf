#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>


/*
*/
int (*checkLflags(char ch))(va_list valist, int *index, char ch)
{
	int j;

	constFormat m[] = {
		{'u', printLongUnsigned},
		{'d', printLongSigned},
		{'i', printLongSigned},
		{'x', printLongUnsigned},
		{'X', printLongUnsigned},
		{'o', printLongUnsigned},
		{'\0', NULL}
	};

	for (j = 0; m[j].flags; j++)
	{

		if (ch == m[j].flags)
			return (m[j].handleFlags);
	}
	return (NULL);
		
}
