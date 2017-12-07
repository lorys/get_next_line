/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:54:12 by llopez            #+#    #+#             */
/*   Updated: 2017/12/07 11:07:10 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strndup(const char *s1, int n)
{
	char	*alloc;
	int		i;

	i = -1;
	if (!(alloc = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] && i != n)
	{
		alloc[i] = s1[i];
		i++;
	}
	alloc[i] = 0;
	return (alloc);
}
