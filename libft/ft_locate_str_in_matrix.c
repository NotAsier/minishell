/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_str_in_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:24:03 by aarranz-          #+#    #+#             */
/*   Updated: 2024/09/23 11:24:19 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_locate_str_in_matrix(char **matrix, char *str)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (ft_strncmp(matrix[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-10);
}