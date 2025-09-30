#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/* write one char to stdout */
static int _putchar(char c)
{
	return (write(1, &c, 1) == 1 ? 1 : -1);
}

/* safe strlen */
static int _strlen(const char *s)
{
	int n = 0;

	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

/* print string (NULL -> "(null)") */
static int _puts(const char *s)
{
	const char *p = s ? s : "(null)";
	int i, n = _strlen(p);

	for (i = 0; i < n; i++)
		if (_putchar(p[i]) == -1)
			return (-1);
	return (n);
}

/* handle %c, %s, %%, and unsupported specifiers */
static int handle_percent(char sp, va_list ap)
{
	if (sp == 'c')
	{
		char c = (char)va_arg(ap, int);

		return (_putchar(c));
	}
	if (sp == 's')
	{
		char *str = va_arg(ap, char *);

		return (_puts(str));
	}
	if (sp == '%')
		return (_putchar('%'));

	/* unsupported: print '%' then the specifier char */
	if (_putchar('%') == -1 || _putchar(sp) == -1)
		return (-1);
	return (2);
}

/**
 * _printf - produces output according to a format (supports %c, %s, %%)
 * @format: format string
 * Return: number of characters printed, or -1 on error
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
			{ count = -1; break; }
			count++;
			format++;
			continue;
		}

		format++; /* skip '%' */
		if (!*format)
		{ count = -1; break; }

		r = handle_percent(*format, ap);
		if (r == -1)
		{ count = -1; break; }
		count += r;
		format++;
	}
	va_end(ap);
	return (count);
}

