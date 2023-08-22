#include "main.h"

/**
 * my_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @collabo: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_hexadecimal(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	return (my_hexa(collabo, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * my_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @collabo: List of arguments passed
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get the width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_hexa_upper(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	return (my_hexa(collabo, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * my_hexa - Prints a hexadecimal number in lower or upper
 * @collabo: Lista of arguments
 * @_map_to: Array of values to map to the number
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_cal: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int my_hexa(va_list collabo, char _map_to[], char buffer[],
	int flags, char flag_cal, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(collabo, unsigned long int);
	unsigned long int initialize_num = number;

	UNUSED(width);

	number = conv_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = _map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && initialize_num != 0)
	{
		buffer[i--] = flag_cal;
		buffer[i--] = '0';
	}

	i++;

	return (put_unsgnd(0, i, buffer, flags, width, precision, size));
}
