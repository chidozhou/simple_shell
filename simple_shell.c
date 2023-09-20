#include "shell.h"

/**
 * sig_handler - handles ^C signal interupt
 * @uuv: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void sig_handler(int uuv)
{
	unsigned int sig_flag = 0;
	(void) uuv;

	if (sig_flag == 0)
	{
		my_puts("\n$ ");
	}
	else
	{
		my_puts("\n");
	}
}

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t length_buffer = 0;
	unsigned int itspipe = 0, j;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;

	vars.env = create_environ(environment);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		itspipe = 1;
	if (itspipe == 0)
		my_puts("$ ");
	while (getline(&(vars.buffer), &length_buffer, stdin) != -1)
	{
		vars.count++;
		vars.commands = my_tkenizer(vars.buffer, ";");
		for (j = 0; vars.commands && vars.commands[j] != NULL; j++)
		{
			vars.av = my_tkenizer(vars.commands[j], "\n \t\r");
			if (vars.av && vars.av[0])
				if (my_checkbins(&vars) == NULL)
				{
					mypath_check(&vars);
				}
			free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		if (itspipe == 0)
			my_puts("$ ");
		vars.buffer = NULL;
	}
	if (itspipe == 0)
	{
		my_puts("\n");
	}
	clear_environ(vars.env);
	free(vars.buffer);
	exit(vars.status);
}

