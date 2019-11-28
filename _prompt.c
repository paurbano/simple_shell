#include "shell.h"
/**
 * _prompt - show prompt and read commands
 * Description:  Show promt and read a command
 * Return: string with command
 */

char *_prompt(void)
{
	size_t bufsize = 0;
	int command, mode = 1;
	char *argv = NULL;
	char *h = "$ ";

	if (isatty(STDIN_FILENO) == 0)
		mode = 0;
	mode == 1 ? write(STDOUT_FILENO, h, 2) : mode;

	command = getline(&argv, &bufsize, stdin);
	argv[command - 1] = '\0';

	if (command == EOF)
	{
		if (mode == 1)
			write(STDOUT_FILENO, "\n", 1);
		/*fflush(stdin);*/
		free(argv);
		exit(EXIT_SUCCESS);
	}

	return (argv);
}
/**
 * ctrc - ctrl + c signal
 * @i: signal value
 * Description: trigger when signal is read by standard input
 * Return: nothing
 */

void ctrc(int i)
{
	if (i == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
