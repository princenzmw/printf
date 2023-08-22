#include "main.h"

/**
 * my_int - Print int
 * @collabo: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_int(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num;
	int is_negative = 0;
	long int a = va_arg(collabo, long int);

	a = conv_size_number(a, size);

	if (a == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)a;

	if (a < 0)
	{
		num = (unsigned long int)((-1) * a);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (put_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * my_binary - Prints an unsigned number
 * @collabo: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of char printed.
 */
int my_binary(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int c, d, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	c = va_arg(collabo, unsigned int);
	d = 2147483648; /* (2 ^ 31) */
	a[0] = c / d;
	for (i = 1; i < 32; i++)
	{
		d /= 2;
		a[i] = (c / d) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * my_unsigned - Prints an unsigned number
 * @collabo: The List a of arguments to pass.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get the width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int my_unsigned(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned long int number = va_arg(collabo, unsigned long int);
	int index = BUFF_SIZE - 2;

	number = conv_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[index--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[index--] = (number % 10) + '0';
		number /= 10;
	}

	index++;

	return (put_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * my_octal - Prints an unsigned number in octal notation
 * @collabo: The List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int my_octal(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(collabo, unsigned long int);
	unsigned long int initial_num = number;

	UNUSED(width);

	number = conv_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && initial_num != 0)
	{
		buffer[i--] = '0';
	}
	i++;

	return (put_unsgnd(0, i, buffer, flags, width, precision, size));
}
