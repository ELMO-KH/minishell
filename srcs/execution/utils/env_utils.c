#include "minishell.h"

char *get_env_value(t_env *env, const char *key)
{
    t_env *current = env;

    while (current)
    {
        if (ft_strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }
    return (NULL);
}
t_env *new_env_node(const char *key, const char *value)
{
    t_env *new = malloc(sizeof(t_env));
    if (!new)
        return (NULL);
    new->key = ft_strdup(key);
    new->value = value ? ft_strdup(value) : NULL;
    new->next = NULL;
    if (!new->key || (value && !new->value))
    {
        free(new->key);
        free(new->value);
        free(new);
        return (NULL);
    }
    return (new);
}

void update_env(t_env *env, const char *key, const char *new_value)
{
    t_env *current = env;

    while (current)
    {
        if (ft_strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = ft_strdup(new_value);
            return;
        }
        current = current->next;
    }
}
