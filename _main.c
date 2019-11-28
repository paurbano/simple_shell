#include "shell.h"
/**
 * main - check the code for Holberton School students.
 * @argc : argc contains the number of arguments passed to the program
 * @argv : A vector is a one-dimensional array
 * @env : Enviroment Variable
 * Return: Always 0.
 */

int main(int argc, char *argv[], char **env)
{
	int status = 1;
	char *linea;
	char **args = NULL;
	static int count;

	count = 0;
	signal(SIGINT, ctrc);

	/*(void ) (args);*/
	do {
		linea = _prompt();
		count++;
		exitp(linea);
		/*write(1,linea,15);*/
		/*printf("antes de separar\n");*/
		args = _separaArgs(linea);
		/*printf("argv = %s\n", *args);*/
		if (argc == 1)
		{
			/*printf("modo interactivo\n");*/
			_exec(args, env, argv[0], count);
		}
		else
		{
			/*printf("modo no interactivo");*/
			_exec(argv, env, argv[0], count);
		}
freedp(args);
	} while (status);
/*	free(linea);*/
	/*freedp(args);*/
	exit(0);
}
