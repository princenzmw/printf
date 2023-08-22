#include "main.h"

/**
 * my_pointer - Prints the value of a pointer variable
 * @collabo: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get the width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int my_pointer(va_list collabo, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned long number_addrs;
	char extr_char = 0, pd = ' ';
	int index = BUFF_SIZE - 2, pd_start = 1, length = 2; //length=2, for '0x'
	char _map_to[] = "0123456789abcdef";
	void *addrs = va_arg(collabo, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	number_addrs = (unsigned long)addrs;

	while (number_addrs > 0)
	{
		buffer[index--] = _map_to[number_addrs % 16];
		number_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		pd = '0';
	}
	if (flags & F_PLUS)
	{
		extr_char = '+', length++;
	}
	else if (flags & F_SPACE)
	{
		extr_char = ' ', length++;
	}
	index++;

	return (put_pointer(buffer, index, length,
		width, flags, pd, extr_char, pd_start));
}

