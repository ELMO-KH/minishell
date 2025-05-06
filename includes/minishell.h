#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <signal.h>
# include "libft.h"

# define SUCCESS 0
# define FAILURE 1
# define SYNTAX_ERROR 2
# define CMD_NOT_FOUND 127
# define EXIT_NON_NUMERIC 255

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
}						t_token_type;
typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
}						t_token;
typedef struct s_cmd
{
    char            **args;
    int            in_fd;
    int             out_fd;
    bool            is_append;
    bool            is_heredoc;
    struct s_cmd    *next;
}   t_cmd;

typedef struct s_data
{
    t_env       *env;
    t_cmd       *cmd;
    int         exit_status;
    pid_t       pid;
    bool        is_child;
}   t_data;

/* Builtins */
int     ft_cd(t_data *data, char **args);
int     ft_echo(t_data *data, char **args);
int     ft_exit(t_data *data, char **args);
int     ft_pwd(t_data *data);
int     ft_env(t_data *data, char **args);
int     ft_export(t_data *data, char **args);
int    ft_unset(t_data *data, char **args);

/* Execution */
void    executer(t_data *data, char **envp);
int     execute_builtin(t_data *data);
void    execute_external(t_data *data);

/* Environment */
void init_env(t_data *data, char **envp);
void update_env(t_env *env, const char *key, const char *new_value);
void add_env_node(t_env **env, t_env *new_node);
char *extract_key(char *str);
char *extract_value(char *str);
char *get_env_value(t_env *env, const char *key);
t_env *new_env_node(char *key, char *value);
void sort_and_print_env(t_env *env);
bool	is_valid_key(const char *key);

/* Parsing */
t_cmd   *parse_line(char *line);
char    **split_pipes(const char *input);

/* Memory */
void	free_all_and_exit(t_data *data, int exit_code);
void    free_cmd(t_cmd *cmd);
void    free_env(t_env *env);
void    free_array(char **array);
void    free_data(t_data *data);
void    clean_exit(t_data *data, int exit_code);
void    free_array(char **array);


#endif