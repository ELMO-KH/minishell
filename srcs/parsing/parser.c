#include "../../includes/minishell.h"

static char **split_pipe(char *line)
{
	char **parts = malloc(100 * sizeof(char *));
	int i = 0;
	char *token = strtok(line, "|");

	while (token)
	{
		parts[i++] = strdup(token);
		token = strtok(NULL, "|");
	}
	parts[i] = NULL;
	return parts;
}

static char **split_args(char *cmd)
{
	char **args = malloc(100 * sizeof(char *));
	int i = 0;
	char *token = strtok(cmd, " \t\n");

	while (token)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return args;
}

t_cmd *parse_line(char *line)
{
	t_cmd *head = NULL;
	t_cmd *prev = NULL;
	char **pipes = split_pipe(line);
	int i = 0;

	while (pipes[i])
	{
		t_cmd *cmd = malloc(sizeof(t_cmd));
		cmd->args = split_args(pipes[i]);
		cmd->in_fd = -1;
		cmd->out_fd = -1;
		cmd->is_append = 0;
		cmd->next = NULL;

		if (!head)
			head = cmd;
		else
			prev->next = cmd;
		prev = cmd;
		i++;
	}
	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
	return head;
}
