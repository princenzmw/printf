#include "main.h"

/**
 * my_write_char - Prints a string
 * @ch: char data types.
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters to be printed.
 */
int my_write_char(char ch, char buffer[],
	int flags, int width, int precision, int size)
{
/* The char is stored at left and paddind at buffer's right */
	char paddin = ' ';
	int index = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		paddin = '0';
	}

	buffer[index++] = ch;
	buffer[index] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';

		for (index = 0; index < width - 1; index++)
		{
			buffer[BUFF_SIZE - index - 2] = paddin;
		}

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - index - 1], width - 1));
		}
		else
		{
			return (write(1, &buffer[BUFF_SIZE - index - 1], width - 1) +
					write(1, &buffer[0], 1));
		}
	}

	return (write(1, &buffer[0], 1));
}

/**
 * put_number - Writes a formatted number to the buffer.
 * @is_negative: Indicates if the number is positive.
 * @index: The index in the buffer to start writing.
 * @buffer: The buffer to write to.
 * @flags: The flags for formatting.
 * @width: The minimum width for the printed number.
 * @precision: The precision for printing (ignored for integers).
 * @size: The length modifier size.
 *
 * Return: The index in the buffer after writing the number.
 */
int put_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char paddin = ' ', extr_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		paddin = '0';
	}
	if (is_negative)
	{
		extr_char = '-';
	}
	else if (flags & F_PLUS)
	{
		extr_char = '+';
	}
	else if (flags & F_SPACE)
	{
		extr_char = ' ';
	}

	return (put_num(index, buffer, flags, width, precision,
		length, paddin, extr_char));
}

/**
 * put_unsgnd - Writes the formatted unsigned integer to the buffer.
 * @is_negative: Indicates if the number is negative.
 * @index: The current index in the buffer.
 * @buffer: The buffer to write to.
 * @flags: The formatting flags.
 * @width: The field width.
 * @precision: The precision for formatting.
 * @size: The length modifier size.
 *
 * Return: The updated index in the buffer after writing.
 */
int put_unsgnd(int is_negative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - index - 1, i = 0;
	char paddin = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
	{
		return (0); /*for, printf(".0d", 0) no char is printed */
	}
	if (precision > 0 && precision < length)
		paddin = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddin = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
		{
			buffer[i] = paddin;
		}

		buffer[i] = '\0';
		if (flags & F_MINUS) /* to sign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else /* to Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}

/**
 * put_pointer - Writes the formatted pointer to the buffer.
 * @buffer: The buffer to write to.
 * @index: The current index in the buffer.
 * @length: The length of the formatted pointer.
 * @width: The field width.
 * @flags: The formatting flags.
 * @paddin: The padding character.
 * @extr_char: The extra character for flags.
 * @paddin_start: Indicates if padding should start at the beginning.
 *
 * Return: The updated index in the buffer after writing.
 */
int put_pointer(char buffer[], int index, int length,
	int width, int flags, char paddin, char extr_char, int paddin_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
		{
			buffer[i] = paddin;
		}
		buffer[i] = '\0';
		if (flags & F_MINUS && paddin == ' ')/* extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extr_char)
				buffer[--index] = extr_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && paddin == ' ')/*extra char to left of buffer*/
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extr_char)
				buffer[--index] = extr_char;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && paddin == '0')/*extra char to left of padd */
		{
			if (extr_char)
				buffer[--paddin_start] = extr_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[paddin_start], i - paddin_start) +
				write(1, &buffer[index], length - (1 - paddin_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extr_char)
		buffer[--index] = extr_char;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
