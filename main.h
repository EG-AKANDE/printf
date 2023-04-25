#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *s);
int print_integer(int num);
int format_specifier(const char **format, va_list args);
int print_binary(unsigned int num);


#endif
