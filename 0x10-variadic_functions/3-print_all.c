#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>


/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
*        c: char
*        i: integer
*        f: float
*        s: char * (if the string is NULL, print (nil) instead)
*        any other char should be ignored
* @...: A variable number of arguments to be printed.
*/
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char current_format;
	int printed = 0;

	va_start(args, format);

	while (format && format[i])
	{
	if(printed)
	printf(", ");

	current_format = format[i];
	switch (current_format)
	{
	case 'c':
	printf("%c", va_arg(args, int));
	printed = 1;
	break;
	case 'i':
	printf("%d", va_arg(args, int));
	printed = 1;
	break;
	case 'f':
	printf("%f", va_arg(args, double));
	printed = 1;
	break;
	case 's':
	str = va_arg(args, char *);
	if (str == NULL)
	str = "(nil)";
	printf("%s", str);
	printed = 1;
	break;
	}

	i++;
	}

	printf("\n");
	va_end(args);
	}
