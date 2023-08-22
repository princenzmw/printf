#include "main.h"

/**
 * my_rot13string - Print a string in rot13.
 * @collabo: The List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of characters to be printed.
 */
int my_rot13string(va_list collabo, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int index, j;
	char ch;
	char *str;
	int count = 0;
	char inter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outer[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(collabo, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(AHYY)";
	}
	for (index = 0; str[index]; index++)
	{
		for (j = 0; inter[j]; j++)
		{
			if (inter[j] == str[index])
			{
				ch = outer[j];
				write(1, &ch, 1);
				count++;
				break;
			}
		}
		if (!inter[j])
		{
			ch = str[index];
			write(1, &ch, 1);
			count++;
		}
	}
	return (count);
}
