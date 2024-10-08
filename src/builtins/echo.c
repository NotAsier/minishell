#include "minishell.h"

int	ft_echo(char **commands)
{
	int	i;
	int	menos_n;

	i = 0;
	menos_n = 0;
	if (commands[1] && ft_strcmp(commands[1], "-n") == 0)
	{
		i++;
		menos_n++;
	}
	i++;
	while (commands[i])
	{
		ft_putstr_fd(commands[i], STDOUT_FILENO);
		if (commands[++i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (menos_n == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	ft_free_matrix(commands);
	return (0);
}