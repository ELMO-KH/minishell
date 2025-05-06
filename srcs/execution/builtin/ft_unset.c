#include "minishell.h"

static bool exist(char **args, char *key)
{

}
void    ft_unset(t_data *data, char **args)
{
    int i;

    if (!args[1])
    {
        data->exit_status = 0;
        return ;
    }    
    i = 1;
    while (args[i])
    {
        if(!is_valid_key(args[i]))
        {
            printf("unset: `%s': not a valid identifier", args[i]);
            data->exit_status = 1;
            exit(1);
        }
    }
}
