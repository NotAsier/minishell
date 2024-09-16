#include "minishell.h"

void	ft_print_env(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		printf("%s\n", matrix[i]);
}

int	ft_env(char **env, char **commands)
{
	ft_print_env(env);
	ft_free_matrix(commands);
	return (0);
}