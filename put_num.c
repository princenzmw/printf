#include "main.h"

/**
 * write_padding - Write padding characters to the buffer.
 * @buffer: buffer
 * @start: padding start
 * @end: padding end
 * @paddin: padding
 *
 * Return: nothing
 */
static void write_padding(char buffer[], int start, int end, char paddin)
{
	int i;

	for (i = start; i < end; i++)
	{
		buffer[i] = paddin;
	}
}

/**
 * write_extra_char - Write extra character and return new index.
 * @buffer: buffer
 * @index: index number
 * @extr_char: extar character
 *
 * Return: index
 */
static int write_extra_char(char buffer[], int index, char extr_char)
{
	if (extr_char != 0)
	{
		buffer[--index] = extr_char;
	}
	return (index);
}

/**
 * write_buffer_content - Write content to buffer and return the new index.
 * @buffer: buffer
 * @start: content start
 * @length: buffer length
 *
 * Return: buffer contents
 */
static int write_buffer_content(char buffer[], int start, int length)
{
	return (write(1, &buffer[start], length));
}

/**
 * put_num - Write a number using a bufffer
 * @index: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precis: Precision specifier
 * @length: Number length
 * @paddin: Pading char
 * @extr_char: Extra char
 * Return: Number of printed chars.
 */
int put_num(int index, char buffer[], int flags, int width, int precis,
		int length, char paddin, char extr_char)
{
	int paddin_start = 1;

	if (precis == 0 && index == BUFF_SIZE - 2 &&
	    buffer[index] == '0' && width == 0)
		return (0); /* for printf(".0d", 0) no char is printed */
	if (precis == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = paddin = ' '; /* wdth is displayed with padding ' ' */
	if (precis > 0 && precis < length)
		paddin = ' ';
	while (precis > length)
		buffer[--index] = '0', length++;
	if (extr_char != 0)
		length++;
	if (width > length)
	{
		write_padding(buffer, 1, width - length + 1, paddin);
		buffer[width - length + 1] = '\0';

		if (flags & F_MINUS && paddin == ' ')
		{
			index = write_extra_char(buffer, index, extr_char);
			return (write_buffer_content(buffer, index, length) +
				write_buffer_content(buffer, 1, width - length));
		}
		else if (!(flags & F_MINUS) && paddin == ' ')
		{
			index = write_extra_char(buffer, index, extr_char);
			return (write_buffer_content(buffer, 1, width - length) +
				write_buffer_content(buffer, index, length));
		}
		else if (!(flags & F_MINUS) && paddin == '0')
		{
			index = write_extra_char(buffer, index, extr_char);
			index = write_buffer_content(buffer, paddin_start, index - paddin_start);
			return (index + write_buffer_content(buffer, index,
					length - (1 - paddin_start)));
		}
	}
	index = write_extra_char(buffer, index, extr_char);
	return (write_buffer_content(buffer, index, length));
}
