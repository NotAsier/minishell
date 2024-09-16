#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

void	ft_print_error(char *str);
void	ft_perror(char *str);

char	**ft_get_env(char **env);

#endif