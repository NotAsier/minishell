/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:22:57 by aarranz-          #+#    #+#             */
/*   Updated: 2024/09/23 11:23:04 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char	*final;
	int		i;

	i = 0;
	final = malloc(sizeof(char) * len + 1);
	if (!final)
		return (NULL);
	while (s1[i] && i < len)
	{
		final[i] = s1[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}