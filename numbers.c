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

