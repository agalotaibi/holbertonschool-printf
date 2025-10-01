#include "main.h"
#include <unistd.h>

/**
 * putch_ - local helper to write one char
 * @c: char to print
 * Return: 1 on success, -1 on error
 */
static int putch_(char c)
{
	return (write(1, &c, 1) == 1 ? 1 : -1);
}

/**
 * print_number - Print an integer using write (supports negatives)
 * @n: number to print
 * Return: number of chars printed, or -1 on error
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		if (putch_('-') == -1)
			return (-1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		int r = print_number(num / 10);

		if (r == -1)
			return (-1);
		count += r;
	}
	if (putch_((num % 10) + '0') == -1)
		return (-1);
	count++;

	return (count);
}



/**
 * print_unsigned_base - Print an unsigned int in a given base
 * @num: number to print
 * @base: base to convert to (2, 8, 10, 16)
 * @uppercase: flag, if 1 use A-F else a-f
 * Return: number of chars printed, or -1 on error
 */
int print_unsigned_base(unsigned int num, int base, int uppercase)
{
    char buffer[32]; 
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0, count = 0;

    
    if (num == 0)
    {
        if (putch_('0') == -1)
            return (-1);
        return (1);
    }

    while (num > 0)
    {
        buffer[i++] = digits[num % base];
        num /= base;
    }

    while (--i >= 0)
    {
        if (putch_(buffer[i]) == -1)
            return (-1);
        count++;
    }

    return (count);
}
