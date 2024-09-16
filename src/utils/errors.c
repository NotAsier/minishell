#include "minishell.h"

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}