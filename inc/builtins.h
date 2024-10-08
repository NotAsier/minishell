#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		builtins(char *str);

/*__SIGNALS___*/
void	manage_signal(void);
void	execution_signal_init(void);
void	execution_signal_hadler(int sig);

/*__PWD_____*/
int		ft_pwd(char **commands);

/*__ENV_____*/
int		ft_env(char **env, char **commands);

/*__CD______*/
int		ft_cd(char **env, char **commands);

/*__ECHO____*/
int		ft_echo(char **commands);

/*__EXPORT__*/
int		ft_export(char **env, char **args);

/*__UNSET___*/
int		ft_unset(char **env, char **args);

/*__EXIT____*/

#endif