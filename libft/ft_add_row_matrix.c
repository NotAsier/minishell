/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_row_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:28:55 by aarranz-          #+#    #+#             */
/*   Updated: 2024/09/23 11:29:42 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_row_matrix(char **matrix, char *new_row)
{
	int		i;
	char	**aux;

	if (!matrix)
		return (NULL);
	if (!new_row)
		return (matrix);
	aux = ft_calloc(sizeof(char *), (ft_len_matrix(matrix) + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while (i < ft_len_matrix(matrix))
	{
		aux[i] = malloc(sizeof(char) * (ft_strlen(matrix[i]) + 1));
		if (!aux[i])
			return (ft_free_matrix(aux), NULL);
		ft_strncpy(aux[i], matrix[i], ft_strlen(matrix[i]) + 1);
		i++;
	}
	aux[i] = ft_calloc(sizeof(char), (ft_strlen(new_row) + 1));
	if (!aux[i])
		return (ft_free_matrix(aux), NULL);
	ft_strncpy(aux[i++], new_row, ft_strlen(new_row) + 1);
	return (aux);
}