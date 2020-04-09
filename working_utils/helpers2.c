#include "protos.h"
/**
  * *_strcpy - copies the string pointed
  *to by src, including the terminating null byte
  *to the buffer pointed to by dest
  * @dest: points to buffer
  * @src: points to string
  *
  * Return: pointer
  */
char *_strcpy(char *dest, char *src)
{
	char *answer = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
return (answer);
}
/**
  * *_strcat - a function to concatenate 2 strings
  * @dest: what we are apprending to
  * @src: the string we are appending from
  * Return: char
  */
char *_strcat(char *dest, char *src)
{
	char *begin = dest;

	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
return (begin);
}
/**
 * _strncmp - compare two strings by int n
 * @s: one string
 * @t: the other
 * @n: how many chars compared
 * Return: 0, 1, or diff
 */
int _strncmp(char *s, char *t, int n)
{

	if (_strlen(s) == _strlen(t))
	{
		while (*s == *t && *s && n)
		n--, s++, t++;

		if (!n)
			return (0);
		else
			return (1);
	}
	else
		return (_strlen(s) - _strlen(t));
}
