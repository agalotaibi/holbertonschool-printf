#include "main.h"

/**
* _printf - Produces output according to a format.
* @format: The format string.
*
* Return: The number of characters printed.
*/

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i = 0;

va_start(args, format);

while (format && format[i] != '\0')
{
if (format[i] == '%')
{
i++;

if (format[i] == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 's')
{
char *s = va_arg(args, char *);
int j = 0;
while (s[j] != '\0')
{
write(1, &s[j], 1);
count++;
j++;
}
}
else if (format[i] == '%')
{
write(1, &format[i], 1);
count++;
}
}
else
{
write(1, &format[i], 1);
count++;
}
i++;
}

va_end(args);

return (count);
}
