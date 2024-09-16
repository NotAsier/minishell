#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc, (void)argv;
	ft_memset(&g_c, 0, sizeof(t_cosas));
	g_c.env = ft_get_env(env);
	g_c.dolar_q = 42;
	manage_signal();
	readline_create();
	exit(EXIT_SUCCESS);
	return (0);
}