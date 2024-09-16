#include "minishell.h"

char	*copy_join(char *str1, char *str2, t_expand *expand)
{
	int	j;

	j = 0;
	while (str2[j])
	{
		str1[expand->j] = str2[j];
		expand->j++;
		j++;
	}
	return (str1);
}