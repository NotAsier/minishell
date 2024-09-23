/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_row_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:25:42 by aarranz-          #+#    #+#             */
/*   Updated: 2024/09/23 11:45:39 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_count
{
	int	i;
	int	j;
	int	len;
}	t_count;

char	**allocate_matrix(char **matrix, int delete, int *len)
{
	char	**aux;

	if (!matrix)
		return (NULL);
	*(len) = ft_len_matrix(matrix);
	if (delete > *(len))
		return (matrix);
	aux = malloc(sizeof(char *) * *(len));
	if (!aux)
		return (NULL);
	return (aux);
}

char	**ft_delete_row_matrix(char **matrix, int delete)
{
	char	**aux;
	t_count	c;

	ft_memset(&c, 0, sizeof(t_count));
	aux = allocate_matrix(matrix, delete, &c.len);
	if (!aux)
		return (NULL);
	if (delete > c.len)
		return (matrix);
	while (c.i < c.len)
	{
		if (c.i != delete)
		{	
			aux[c.j] = malloc(sizeof(char) * (ft_strlen(matrix[c.i]) + 1));
			if (!aux[c.j])
				return (ft_free_matrix(aux), NULL);
			ft_strncpy(aux[c.j], matrix[c.i], ft_strlen(matrix[c.i]) + 1);
			c.j++;
		}
		c.i++;
	}
	aux[c.j] = NULL;
	return (aux);
}
