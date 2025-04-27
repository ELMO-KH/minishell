#include "minishell.h"

void add_env_node(t_env **env_list, char *key, char *value)
{
    t_env *new_node = malloc(sizeof(t_env));
    if (!new_node)
        return;
    new_node->key = ft_strdup(key);
    new_node->value = ft_strdup(value);
    new_node->next = *env_list;
    *env_list = new_node;
}


void add_back_env(t_env **env, t_env *new)
{
    if (!*env)
        *env = new;
    else
    {
        t_env *tmp = *env;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void init_env(t_data *data, char **envp)
{
    int i;
    char *equal;
    t_env *node;

    data->env = NULL;
    i = 0;
    while (envp[i])
    {
        equal = ft_strchr(envp[i], '=');
        if (equal)
        {
            node = new_env_node(envp[i], equal);
            add_back_env(&data->env, node);
        }
        i++;
    }
}
