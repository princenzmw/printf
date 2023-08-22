#include "main.h"

/**
 * my_char - Prints a char
 * @collabo: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int my_char(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	char ch = va_arg(collabo, int);

	return (my_write_char(ch, buffer, flags, width, precision, size));
}

/**
 * my_string - Prints a string
 * @collabo: The List a of arguments to pass
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_string(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(collabo, char *);
	int length = 0, index;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (index = width - length; index > 0; index--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (index = width - length; index > 0; index--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * my_percent - Prints a percent sign
 * @collabo: The List of arguments to pass
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get the width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_percent(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(collabo);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

