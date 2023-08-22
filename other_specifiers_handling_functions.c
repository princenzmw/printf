#include "main.h"

/**
 * the_flags - Retrieves formatting flags from the format string.
 * @format: The format string.
 * @i: A pointer to the current position to take parameter
 *	in the format string.
 *
 * Return: The accumulated flags value.
 */
int the_flags(const char *format, int *i)
{
	int j, current_indx;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_indx = *i + 1; format[current_indx] != '\0'; current_indx++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[current_indx] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = current_indx - 1;

	return (flags);
}

/**
 * the_width - Retrieves the width specifier from the format string.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 * @prinko: The list of arguments.
 *
 * Return: The width value or -1 if not found.
 */
int the_width(const char *format, int *i, va_list prinko)
{
	int current_indx;
	int width = 0;

	for (current_indx = *i + 1; format[current_indx] != '\0'; current_indx++)
	{
		if (is_digit(format[current_indx]))
		{
			width *= 10;
			width += format[current_indx] - '0';
		}
		else if (format[current_indx] == '*')
		{
			current_indx++;
			width = va_arg(prinko, int);
			break;
		}
		else
			break;
	}

	*i = current_indx - 1;

	return (width);
}

/**
 * the_precision - Retrieves the precision value from the format string.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 * @prinko: The va_list containing the arguments.
 *
 * Return: The precision value.
 */
int the_precision(const char *format, int *i, va_list prinko)
{
	int current_indx = *i + 1;
	int precision = -1;

	if (format[current_indx] != '.')
		return (precision);

	precision = 0;

	for (current_indx += 1; format[current_indx] != '\0'; current_indx++)
	{
		if (is_digit(format[current_indx]))
		{
			precision *= 10;
			precision += format[current_indx] - '0';
		}
		else if (format[current_indx] == '*')
		{
			current_indx++;
			precision = va_arg(prinko, int);
			break;
		}
		else
			break;
	}

	*i = current_indx - 1;

	return (precision);
}

/**
 * the_size - Retrieves the length modifier size from the format string.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 *
 * Return: The length modifier size value.
 */
int the_size(const char *format, int *i)
{
	int current_indx = *i + 1;
	int size = 0;

	if (format[current_indx] == 'l')
		size = S_LONG;
	else if (format[current_indx] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current_indx - 1;
	else
		*i = current_indx;

	return (size);
}
