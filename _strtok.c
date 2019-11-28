#include <stdlib.h>
/**
 * _strtok -  extract tokens from strings.
 * @str:string to tokenize
 * @delimit: delimiters to tokenize string
 * Description:  extract tokens from strings
 * Return: char array of tokens
 */
char *_strtok(char *str, char *delimit)
{
static int pos;
static char *s;
int start = pos, j = 0;

if (str != NULL)
s = str;
while (s[pos] != '\0')
{
j = 0;
while (delimit[j] != '\0')
{
if (s[pos] == delimit[j])
{
/*Replace the delimter by \0 to break the string*/
s[pos] = '\0';
pos = pos + 1;
if (s[start] != '\0')
{
return (&s[start]);
}
else
{
/* Move to the next string after the delimiter*/
start = pos;
/* Decrementing as it will be incremented at the end of the while loop*/
pos--;
break;
}
}
j++;
}
pos++;
}
s[pos] = '\0';
if (s[start] == '\0')
return (NULL);
else
return (&s[start]);
}
