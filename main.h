#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *s);
int print_integer(int num);
int format_specifier(const char **format, va_list args);
int format_specifier1(const char **format, va_list args);
int print_unsigned_integer(unsigned int num);
int print_octal(unsigned int num);
int print_hexadecimal(unsigned int num, char specifier);
int handle_format_specifier(const char **format, va_list args);
int handle_format_specifier1(const char **format, va_list args);
int print_binary(unsigned int num);

#endif
