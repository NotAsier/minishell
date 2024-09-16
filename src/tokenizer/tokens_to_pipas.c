#include "minishell.h"

int	token_is_symbol(char *token)
{
	int			i;
	static char	*symbols[] = {"<", "<<", ">", ">>", "|", NULL};

	i = -1;
	if (!token)
		return (0);
	while (symbols[++i])
		if (ft_strcmp(token, symbols[i]) == 0)
			return (1);
	return (0);
}

int	count_pipas(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	if (tokens[i] != NULL)
		count = 1;
	while (tokens[i])
	{
		if (token_is_symbol(tokens[i]) == 1 && tokens[i + 1]
			&& token_is_symbol(tokens[i + 1]) != 1)
			count += 2;
		else if (tokens[i] && token_is_symbol(tokens[i]) == 1 && !tokens[i + 1])
			count ++;
		i++;
	}
	return (count);
}

void	join_commands(char **final, char **tokens, int *i, int *j)
{
	if (final[*(j)] == NULL)
		final[*(j)] = ft_strdup(tokens[*(i)]);
	else
	{
		final[*(j)] = ft_strjoin(final[*(j)], " ");
		final[*(j)] = ft_strjoin(final[*(j)], tokens[*(i)]);
	}
}

char	**tokens_to_pipas(char **tokens)
{
	int		i;
	int		j;
	char	**final;

	i = 0;
	j = 0;
	final = (char **)ft_calloc(sizeof(char *), (count_pipas(tokens) + 1));
	if (!final)
		return (tokens);
	while (tokens[i])
	{
		if (token_is_symbol(tokens[i]))
		{
			if (i != 0)
				j++;
			final[j] = ft_strdup(tokens[i]);
			j++;
		}
		if (!token_is_symbol(tokens[i]))
			join_commands(final, tokens, &i, &j);
		i++;
	}
	final[count_pipas(tokens)] = NULL;
	return (final);
}

int	double_symbols(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (token_is_symbol(tokens[i]) == 1 && tokens[i + 1]
			&& token_is_symbol(tokens[i + 1]))
			return (1);
		i++;
	}
	if (tokens[i - 1] && token_is_symbol(tokens[i - 1]) == 1)
		return (1);
	return (0);
}