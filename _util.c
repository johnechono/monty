#include <ctype.h>
#include "monty.h"

/**
 * is_digit - will checks if the string is a digit
 * @string: the string to  be checked
 * Return: 1 O/W 0
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
		{
			return (0);
		}
		string++;
	}
	return (1);
}
/**
 * is_number - will checks if the string is a number
 * @str: the string
 * Return: 1 O/W 0
 */
int is_number(char *str)
{
	int j;

	if (!str)
	{
		return (0);
	}
	for (j = 0; str[j]; j++)
		if (j < '0' || j > '9')
		{
			return (0);
		}
	return (1);
}
