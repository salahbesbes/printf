#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int i, *index, nbOfCharAdded = 0;
	int (*funcOfEachType)(va_list valist, int *index);
	index = &i;
	
	va_start(valist, format);
	if (format == NULL)
		return (0);
	i = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{	/*
			   char *allFlags;
			allFlags = getAllFlags(i, (char *)format);
			checkflags(allFlags);
			printf(" allFlags = %s\n", allFlags);
			treatAllCases(format, index, &nbOfCharAdded, valist);
			*/
			if (format[i + 1] == '%')
			{
				_putchar(format[i + 1]);
				i += 2;
				continue;;
			}
			if (format[i + 1] == '\0')
			{
				i++;
				continue;
			}
			funcOfEachType = checkType(format[i + 1]);
			if (funcOfEachType)
				nbOfCharAdded += funcOfEachType(valist, index);
			else 
				i++;
			continue;
			/*
			*/
		}
		_putchar(format[i]);
		i++;
	}
	va_end(valist);
	return (i + nbOfCharAdded);
}