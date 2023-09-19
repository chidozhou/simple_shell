#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>


/**
 * struct my_variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: double pointer to commands
 */
typedef struct my_variables
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} vars_t;

/**
 * struct my_builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct my_builtins
{
	char *name;
	void (*f)(vars_t *);
} my_bins;

char **create_environ(char **myenv);
void clear_environ(char **myenv);
ssize_t my_puts(char *strng);
char *my_strdup(char *mystrtodup);

int my_strcmpr(char *mystrcmp1, char *mystrcmp2);
char *my_strcat(char *mystrc1, char *mystrc2);
unsigned int my_strlen(char *strng);

char **my_tkenizer(char *buff, char *mydlimiter);
char **my_rllocat(char **myptr, size_t *mysize);
char *my_strtok(char *mystr, const char *mydelim);

void (*my_checkbins(vars_t *myvars))(vars_t *myvars);
void my_exit(vars_t *myvars);
void my_env(vars_t *myvars);

void myset_environ(vars_t *myvars);
void myunset_environ(vars_t *myvars);
void mykey_add(vars_t *myvars);

char **mykey_find(char **myenv, char *mykey);
char *myvalue_add(char *mykey, char *myvalue);
int my_atoi(char *mystr);

void mypath_check(vars_t *myvars);
int mypath_exe(char *mycommand, vars_t *myvars);
char *mypath_find(char **myenv);
int mycwd_exe(vars_t *myvars);

int mydir_check(char *mystr);
void myerror_print(vars_t *myvars, char *mymsg);
void myputs2(char *mystr);
char *my_uitoa(unsigned int mycount);


#endif /* _SHELL_H_ */

