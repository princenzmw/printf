#include "main.h"

void my_buffr(char buffer[], int *buffr_index);

/**
 * _printf - Displays text and data on a console or terminal.
 * @format: A string parameter that defines the formatting of the output.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffr_index = 0;
	va_list prinko;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(prinko, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffr_index++] = format[i];
			if (buffr_index == BUFF_SIZE)
			{
				my_buffr(buffer, &buffr_index);
			}
			//write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			my_buffr(buffer, &buffr_index);
			flags = the_flags(format, &i);
			width = the_width(format, &i, prinko);
			precision = the_precision(format, &i, prinko);
			size = the_size(format, &i);
			++i;
			printed = my_printf(format, &i, prinko, buffer,
				flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}

	my_buffr(buffer, &buffr_index);

	va_end(prinko);

	return (printed_chars);
}

/**
 * my_buffr - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffr_index: Index at which to add next char, represents the length.
 */
void my_buffr(char buffer[], int *buffr_index)
{
	if (*buffr_index > 0)
	{
		write(1, &buffer[0], *buffr_index);
	}

	*buffr_index = 0;
}

