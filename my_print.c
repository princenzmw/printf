#include "main.h"
/**
 * my_printf - Processes and prints arguments based on their types
 * @fudji: Formatted string specifying the arguments types.
 * @indx: Index indicating the current position in the format string.
 * @prinko: list of arguments to be printed.
 * @buffer: Buffer array to handle the printed output.
 * @flags: Calculates active flags indicating formatting options.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size modifier for formatting.
 *
 * Return: 1 or 2;
 */
int my_printf(const char *fudji, int *indx, va_list prinko, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_length = 0, printed_chars = -1;
	gringo fresh[] = {
		{'c', my_char}, {'s', my_string}, {'%', my_percent},
		{'i', my_int}, {'d', my_int}, {'b', my_binary},
		{'u', my_unsigned}, {'o', my_octal}, {'x', my_hexadecimal},
		{'X', my_hexa_upper}, {'p', my_pointer}, {'S', my_non_printable},
		{'r', my_reverse}, {'R', my_rot13string}, {'\0', NULL}
	};
	for (i = 0; fresh[i].fudji != '\0'; i++)
		if (fudji[*indx] == fresh[i].fudji)
			return (fresh[i].handler(prinko, buffer, flags, width, precision, size));

	if (fresh[i].fudji == '\0')
	{
		if (fudji[*indx] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (fudji[*indx - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (fudji[*indx] != ' ' && fudji[*indx] != '%')
				--(*indx);
			if (fudji[*indx] == ' ')
				--(*indx);
			return (1);
		}
		unknown_length += write(1, &fudji[*indx], 1);
		return (unknown_length);
	}
	return (printed_chars);
}

