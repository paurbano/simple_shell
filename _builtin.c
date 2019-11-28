#include "shell.h"
#define maxlen_cmd 100
/**
 * _builtin - Run a builtin command
 * @cmd: builtin command
 * @env: variable enviroment
 * Description:  return 1 if is, 0 if not
 * Return: int
 */
int _builtin(char **cmd, char **env)
{
	int CantBuiltins = 0, i, command = 0;
	char *ListOfBuiltIns[] = {"cd", "env", "help"};

	CantBuiltins = sizeof(ListOfBuiltIns) / sizeof(char *);
	for (i = 0; i < CantBuiltins; i++)
	{
		/*printf("cmd:%s, Built:%s ",cmd[0],ListOfBuiltIns[i]);*/
		if (_strcmp(cmd[0], ListOfBuiltIns[i]) == 0)
		{
			command = i + 1;
			break;
		}
	}

	switch (command)
	{
	case 1:
		hsh_cd(cmd, env);
		return (1);
	case 2:
		hsh_env(env);
		return (1);
	case 3:
		/*printf("help");*/
		return (1);
	case 4:
		/*printf("mkdir");*/
		return (1);
	default:
		return (0);
	}

	return (0);
}

/**
 * hsh_cd - runs cd command
 * @cmd: builtin command
 * @env: enviroment variable
 * Description:  Runs builtin CD command
 * Return: nothing
 */
void hsh_cd(char **cmd, char **env)
{
	char PWD[maxlen_cmd];
	char *HOME;

	if (cmd[1] == NULL)
	{
		HOME = get_env_var("HOME", env);
		chdir(HOME);
		return;
	}
	if (chdir(cmd[0]) != 0)
		perror("-hsh: cd");
	else
		getcwd(PWD, _strlen(cmd[0]));
}

/**
 * hsh_env - runs env command
 * @env: enviroment variable
 * Description:  Print enviroment variable
 * Return: nothing
 */

void hsh_env(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		/*printf("%s\n", env[i]);*/
		i++;
	}
}
