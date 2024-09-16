#include "minishell.h"

void	store_tokens(const char *str, char **tokens)
{
	t_count	c;
	int		len;

	ft_memset(&c, 0, sizeof(t_count));
	while (str[c.i])
	{
		main_while(str, &c);
		len = c.i - c.j;
		if (len != 0)
		{
			tokens[c.k] = ft_strndup(str + c.j, len);
			c.k++;
		}
		c.j = c.i;
		if (char_is_symbol(str[c.i], ">|<") == 1)
		{
			if_char_is_symbol(str, &c, &len);
			tokens[c.k] = ft_strndup(str + c.j, len);
			c.k++;
		}
		if (str[c.i])
			c.i++;
		c.j = c.i;
	}
	tokens[c.k] = NULL;
}