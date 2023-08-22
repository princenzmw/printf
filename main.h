#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
/* Buffer Size */
#define BUFF_SIZE 1024

/* Formatting Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Length Modifiers */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fudji - Represents a format specifier and its associated function.
 *
 * @fudji: The format specifier.
 * @handler: The function associated to struct.
 */
struct fudji
{
	char fudji;
	int (*handler)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fudji gringo - Represents a format specifier
 *	and its function.
 *
 * @fudji: The format specifier
 * @gringo: The associated function
 */
typedef struct fudji gringo;

int _printf(const char *format, ...);
int my_printf(const char *fudji, int *indx,
		va_list prinko, char buffer[], int flags, int width,
		int precision, int size);

//Character and String Printing Functions
int my_char(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_string(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_percent(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);

//Number Printing Functions
int my_int(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_binary(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_unsigned(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_octal(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_hexadecimal(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);
int my_hexa_upper(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);

int my_hexa(va_list collabo, char _map_to[],char buffer[],
		int flags, char flag_cal, int width, int precision, int size);

//Non-Printable Character Printing Function
int my_non_printable(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);

//Memory Address Printing Function
int my_pointer(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);

//Other Specifiers Handling Functions
int the_flags(const char *format, int *i);
int the_width(const char *format, int *i, va_list prinko);
int the_precision(const char *format, int *i, va_list prinko);
int the_size(const char *format, int *i);

// Printing String Reversal Function
int my_reverse(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);

//String Rot13 Conversion Function
int my_rot13string(va_list collabo, char buffer[],
		int flags, int width, int precision, int size);

//Width Handling Function
int my_write_char(char ch, char buffer[],
		int flags, int width, int precision, int size);
int put_number(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size);
int put_num(int index, char buffer[], int flags, int width, int precis,
		int length, char paddin, char extr_char);
int put_pointer(char buffer[], int index, int length,
		int width, int flags, char paddin, char extr_char, int paddin_start);
int put_unsgnd(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size);

//Utility functions
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int conv_size_number(long int number, int size);
long int conv_size_unsgnd(unsigned long int number, int size);

#endif 

