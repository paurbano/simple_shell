#include "shell.h"
/**
 * _exec - executes a command
 * @args: command with arguments
 * @env: enviroment variable
 * @av:argumments passed via nointeractive mode
 * @count: counter executes
 * Description: executes a command .
 * Return: integer
 */

void _exec(char **args, char **env, char av[], int count)
{
	char *path, *val_path;
	int status, builtin = 0, exerror;
	pid_t pid;
	struct stat stat_tok;

	if (args[0] != NULL)
		builtin = _builtin(args, env);
	if (builtin == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (stat(args[0], &stat_tok) == 0)
			{
				/*printf("comando con ruta relativa\n");*/
				exerror = execve(args[0], args, NULL);
				exerror == -1 ? msg(av, count, args, 127) : exerror;
				/*exit(127);*/
			}
			else
			{
				/*printf("A buscar ruta\n");*/
				val_path = get_env_var("PATH", env);
				path = get_cmd_path(val_path, args[0]);
				exerror = execve(path, args, NULL);
				exerror == -1 ? msg(av, count, args, 127) : exerror;
				/*exit(127);*/
			}
		}
		if (pid < 0)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(-1, &status, 0);
		}
	}
}

/**
 * get_env_var - searches for a variable on env.
 * @variable: name of variable
 * @env: enviroment variable
 * Description:search for PATH variable
 * Return: value of variable
 */
char *get_env_var(char *variable, char **env)
{
	char *varvalue, *paths;
	int i = 0, k = 0;
	unsigned int j = 0;

	while (env[i] != NULL)
	{
		varvalue = env[i];
		/*found variable PATH*/
		for (j = 0; j <= 3 && (varvalue[j] == variable[j]) ; j++)
			;
		if (j == 4)
		{
			paths = malloc(sizeof(char) * _strlen(varvalue));
			for (j = 5; j <= _strlen(varvalue) ; j++, k++)
				*(paths + k) = *(varvalue + j);
			paths[k] = '\0';
			return (paths);
			free(paths);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_cmd_path - return valid path for command
 * @varvalue: value of path variable
 * @command: command to execute
 * Description: return valid path to execute command
 * Return: string with path+command
 */

char *get_cmd_path(char *varvalue, char *command)
{
	char *cmdPath, *paths;
	int sizecmd;
	struct stat stat_cmd;

	paths = _strtok(varvalue, ":");
	sizecmd = _strlen(paths) + _strlen(command) + 1;

	while (paths != NULL)
	{
		cmdPath = malloc(sizeof(char) * (sizecmd));
		if (cmdPath == NULL)
			perror("Path error:");

		_strcat(cmdPath, paths);
		_strcat(cmdPath, "/");
		_strcat(cmdPath, command);

		if (stat(cmdPath, &stat_cmd) == 0)
			return (cmdPath);
		free(cmdPath);
		paths = _strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * exitp - free command buffer.
 * @buffer: command read
 * Description: free buffer
 * Return: nothing
 */
void exitp(char *buffer)
{
	if (_strcmp("exit", buffer) == 0 && buffer != NULL)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}


/**
 * msg - error message
 * @av: non interactive
 * @count: counter
 * @args: interactive
 * @error: number
 * Description: free buffer
 * Return: 0
 */
int msg(char av[], int count, char **args, int error)
{
write(STDOUT_FILENO, av, _strlen(av));
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, &count, 2);
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, args[0], _strlen(args[0]));
write(STDOUT_FILENO, ": ", 2);
if (error == 126)
	write(STDOUT_FILENO, "Permission denied\n", 10);
else
	write(STDOUT_FILENO, "Not Found\n", 10);
	exit(127);

return (0);
}
