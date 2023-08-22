#include "main.h"

/**
 * my_non_printable - Prints ascii codes in hexa of non printable chars
 * @collabo: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int my_non_printable(va_list collabo, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, group = 0;
	char *str = va_arg(collabo, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		{
			buffer[i + group] = str[i];
		}
		else
		{
			group += append_hexa_code(str[i], buffer, i + group);
		}

		i++;
	}

	buffer[i + group] = '\0';

	return (write(1, buffer, i + group));
}

