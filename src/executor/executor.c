#include "minishell.h"

void	pipas_handler(void)
{
	int	i;
	int	status;
	int	pid;
	int	type;

	i = 0;
	if (g_c.pipas == 0)
	{
		type = what_cmd(g_c.tokens[i]);
		if (type == BUILTIN)
			g_c.dolar_q = builtins(g_c.tokens[i]);
		else if (type == STDLIB)
		{
			pid = fork();
			if (pid == 0)
				ft_exec(g_c.tokens[i]);
			waitpid(-1, &status, 0);
			g_c.dolar_q = status;
		}
		else
			cmd_not_found(g_c.tokens[i]);
	}
	else
		return ;
}

void	piperrak(int i)
{
	pid_t	pid;

	if (pipe(g_c.fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == 0)
	{
		if (i != g_c.pipas * 2)
			dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
		if (builtins(g_c.tokens[i]) != NONE)
			exit(0);
		ft_exec(g_c.tokens[i]);
	}
	else
	{
		dup2(g_c.fd[READ_END], STDIN_FILENO);
		if (g_c.fd[WRITE_END] != STDIN_FILENO)
			close(g_c.fd[WRITE_END]);
		if (g_c.fd[READ_END] != STDOUT_FILENO)
			close(g_c.fd[READ_END]);
	}
}