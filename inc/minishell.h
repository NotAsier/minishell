#ifndef MINISHELL_H
# define MINISHELL_H

/*__HEADER FILES__*/
# include "minishell.h"
# include "libs.h"

/*__READLINE______*/
# include "readline.h"

/*__TOKENIZER_____*/
# include "tokenizer.h"

/*__EXECUTOR______*/
# include "executor.h"

/*__BUILTINS______*/
# include "builtins.h"

/*__UTILS_________*/
# include "utils.h"

/*__ERROR_MESSAGES_________*/
# include "error_messages.h"

/*__LIBFT_________*/
# include "../libft/inc/libft.h"

# define READ_END	0
# define WRITE_END	1

typedef struct s_cosas {
	char	**env;
	char	**tokens;
	int		tok_count;
	int		flag;
	int		pipas;
	int		dolar_q;
	int		fd[2];
	int		pipe_prev[2];
	int		pipe_current[2];
}	t_cosas;

t_cosas	g_c;

#endif