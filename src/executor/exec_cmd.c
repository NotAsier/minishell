#include "minishell.h"

void	ft_exec(const char *argv)
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(argv, SPACE);
	free((void *)argv);
	if (cmd == NULL)
		exit_failure("malloc", NULL, 1);
	path = cmd[0];
	if (cmd[0][0] != '/' && cmd[0][0] != '.')
	{
		path = only_path(cmd[0]);
		if (!path)
		{
			cmd_not_found(cmd[0]);
			exit_failure(path, cmd, 0);
		}
	}
	execve(path, cmd, g_c.env);
	exit_failure(path, cmd, 1);
}