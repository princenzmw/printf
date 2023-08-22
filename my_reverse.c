#include "main.h"

/**
 * my_reverse - Prints reverse string.
 * @collabo: The List of arguments passed
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int my_reverse(va_list collabo, char buffer[],
		int flags, int width, int precision, int size)
{
	int index, count = 0;
	char *str;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(collabo, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (index = 0; str[index]; index++)
	{
		;
	}

	for (index = index - 1; index >= 0; index--)
	{
		char ch = str[index];

		write(1, &ch, 1);
		count++;
	}
	return (count);
}

