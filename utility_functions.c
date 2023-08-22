#include "main.h"

/**
 * is_printable - Checks if a character is printable.
 * @ch: The character to check.
 *
 * Return: 1 if printable, 0 otherwise.
 */
int is_printable(char ch)
{
	if (ch >= 32 && ch < 127)
	{
		return (1);
	}

	return (0);
}

/**
 * append_hexa_code - Appends hexadecimal code of a character to a buffer.
 * @ascii_dig: The character to append to the code.
 * @buffer: The buffer to append to.
 * @index: The index in the buffer where the code should be appended.
 *
 * Return: The new index after appending the code.
 */
int append_hexa_code(char ascii_dig, char buffer[], int index)
{
	char _map_to[] = "0123456789ABCDEF";
	/* Always the hexa format code is  2 digits long */
	if (ascii_dig < 0)
	{
		ascii_dig *= -1;
	}

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = _map_to[ascii_dig / 16];
	buffer[index] = _map_to[ascii_dig % 16];

	return (3);
}

/**
 * is_digit - Checks if a character is a digit or not.
 * @ch: The character to check.
 *
 * Return: 1 if the ch is a digit, 0 otherwise.
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (1);
	}

	return (0);
}

/**
 * conv_size_number - It Casts a number to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the data type to be casted.
 *
 * Return: Casted value of number
 */
long int conv_size_number(long int number, int size)
{
	if (size == S_LONG)
	{
		return (number);
	}
	else if (size == S_SHORT)
	{
		return ((short)number);
	}

	return ((int)number);
}

/**
 * conv_size_unsgnd - It Casts a number to the specified size
 * @number: The Number to be casted
 * @size: Number indicating the data type to be casted
 *
 * Return: Casted value of number
 */
long int conv_size_unsgnd(unsigned long int number, int size)
{
	if (size == S_LONG)
	{
		return (number);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)number);
	}

	return ((unsigned int)number);
}
