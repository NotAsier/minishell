#include "minishell.h"

int	ft_cd(char **env, char **commands)
{
	char		*path;
	int			i;

	i = 1;
	path = commands[i];
	if (!path)
	{	
		while (env[i])
		{
			if (ft_strncmp("HOME=", env[i], 5) == 0)
				chdir(env[i] + 5);
			i++;
		}
	}
	else if (chdir(path) == -1)
		printf("ESTO NO EXISTE\n");
	ft_free_matrix(commands);
	return (0);
}