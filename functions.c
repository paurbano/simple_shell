#include "shell.h"
/**
 * _strlen - finds length of string..
 * @s: parameter
 * Description: returns the length of a string.
 * Return: int.
 */

int _strlen(char *s)
{
int len = 0;

for ( ; *s != '\0' ; s++)
len = len + 1;
return (len);
}

/**
 * _strcat - concatenate 2 strings
 * @dest: string destination
 * @src: string source
 * Description: concatenate two strings.
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{

char *ptr;
int longitud = 0;

while (dest[longitud] != '\0')
longitud++;

ptr = dest + longitud;

while (*src != '\0')
*ptr++ = *src++;

*ptr = '\0';

return (dest);
}
/**
 * _strcmp - compares tw0 strings
 * @s1: array of integers
 * @s2: Integer
 * Description:  function is similar to the strcmp function,
 * Return: int 0 equal, 1 diferent
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0')
{
if (s1[i] != s2[i])
break;
i++;
}
return (s1[i] - s2[i]);
}
