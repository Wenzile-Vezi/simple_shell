#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR	1
#define CMD_AND	2
#define CMD_CHAIN	3

#define CONV_LOWERCASE	1
#define CONV_UNSIGNED	2

#define USE_STRTOK	0
#define USE_GETLINE	0

#define HIST_MAX  4096
#define HIST_FILE ".simple_shell_history"

extern char **environ;


/**
 * struct list_str - singly linked list
 * @num: number field
 * @str: string
 * @next: points to the next node
 */
typedef struct list_str
{
	int num;
	char *str;
	struct list_str *next;
} list_t;

/**
 * struct pass_info - arguments to pass into a function,
 * @arg: a string containing arguments
 * @argv: an array of strings generated from arg
 * @path: a string path for current command
 * @argc: the argument count
 * @err_num: the error code for exit
 * @line_count: the error count
 * @line_count_flag: if on count this of input
 * @f_name: the programs filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last executed command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: operators and command type
 * @hist_count: the history line number count
 * @read_fd: the fd from which line to read line input
 */
typedef struct pass_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;	
	int err_num;
	unsigned int line_count;
	int line_count_flag;
	char *f_name;
	list_t *env;
	list_t *history;
	list_t *alias;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int hist_count;
	int read_fd;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, NULL, NULL, 0, 0, 0, NULL, NULL, 0, NULL, 0, NULL, \ 0, 0, 0,}

/**
 * struct builtin - a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_t;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *t);
int is_cmd(info_t *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int loophsh(char **);
void _puts(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int interactive(info_t *);
int _isdelim(char, char *);
int _isalpha(int);
int _atoi(char *);
int err_atoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);
size_t get_input(info_t *);
int _getline(info_t *, char **, size_t);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char **get_environ(info_t *);
int _unsetenv(info_t *,char *);
int setenv(info_t *, char *,char *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int line_count);
int renumber_history(info_t*info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t get_node_index(list_t *, list_t *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char  *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif

