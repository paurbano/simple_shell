#include "shell.h"
/**
 * _separaArgs - split command line into tokens
 * @args: command
 * Description: split command into tokens
 * Return: Array with tokens
 */
char **_separaArgs(char *args)
{
char *token;
char **tokens;
int i, len;

i = 0;
len = 64;

token = strtok(args, " ");
tokens = malloc(len *sizeof(char *));
if (tokens == NULL)
return (NULL);

while (token != NULL)
{
tokens[i++] = token;
token = strtok(NULL, " ");
}
tokens[i] = NULL;
return (tokens);
}

/**
 * freedp - free memory for double pointer
 * @dp: command
 * Description: free memory
 * Return: void
 */
void freedp(char **dp)
{
unsigned int i = 0;
if (dp == NULL)
return;
while (dp[i])
{
free(dp[i]);
i++;
}
if (dp[i] == NULL)
free(dp[i]);
free(dp);
}

