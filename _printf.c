#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Write one character to stdout
 * @c: Character to print
 * Return: 1 on success, -1 on error
 */
static int _putchar(char c)
{
	return (write(1, &c, 1) == 1 ? 1 : -1);
}

/**
 * _strlen - Safe strlen
 * @s: Input string (can be NULL)
 * Return: Length if s not NULL, else 0
 */
static int _strlen(const char *s)
{
	int n = 0;

	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

/**
 * _puts - Print string (NULL -> "(null)")
 * @s: String to print
 * Return: Number of chars printed, or -1 on error
 */
static int _puts(const char *s)
{
	const char *p = s ? s : "(null)";
	int i, n = _strlen(p);

	for (i = 0; i < n; i++)
	{
		if (_putchar(p[i]) == -1)
			return (-1);
	}
	return (n);
}

/**
 * handle_percent - Handle %c, %s, %%, %d, %i and unsupported specifiers
 * @sp: Specifier after '%'
 * @ap: va_list
 * Return: Printed count, or -1 on error
 */
static int handle_percent(char sp, va_list ap)
{
	char c, *str;
	int n;

	if (sp == 'c')
	{
		c = (char)va_arg(ap, int);
		return (_putchar(c));
	}
	if (sp == 's')
	{
		str = va_arg(ap, char *);
		return (_puts(str));
	}
	if (sp == 'd' || sp == 'i')
	{
		n = va_arg(ap, int);
		return (print_number(n));
	}
	if (sp == '%')
		return (_putchar('%'));
 if (sp == 'b') 
    {
        unsigned int n = va_arg(ap, unsigned int);
        return (print_unsigned_base(n, 2, 0));
    }
    if (sp == 'u') 
    {
        unsigned int n = va_arg(ap, unsigned int);
        return (print_unsigned_base(n, 10, 0));
    }
    if (sp == 'o') 
    {
        unsigned int n = va_arg(ap, unsigned int);
        return (print_unsigned_base(n, 8, 0));
    }
    if (sp == 'x') 
    {
        unsigned int n = va_arg(ap, unsigned int);
        return (print_unsigned_base(n, 16, 0));
    }
    if (sp == 'X') 
    {
        unsigned int n = va_arg(ap, unsigned int);
        return (print_unsigned_base(n, 16, 1));
    }
	/* unsupported: print '%' then the specifier char */
	if (_putchar('%') == -1 || _putchar(sp) == -1)
		return (-1);
	return (2);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0, r;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (_putchar(*format) == -1)
			{
				count = -1;
				break;
			}
			count++;
			format++;
			continue;
		}

		format++; /* skip '%' */
		if (!*format)
		{
			count = -1;
			break;
		}

		r = handle_percent(*format, ap); /* <-- لازم يكون موجود */
		if (r == -1)
		{
			count = -1;
			break;
		}
		count += r;
		format++;
	}
	va_end(ap);
	return (count);
}

