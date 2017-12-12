/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:54:12 by llopez            #+#    #+#             */
/*   Updated: 2017/12/12 17:46:47 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char				*ft_strndup(const char *s1, int n)
{
	char	*alloc;
	int		i;

	i = -1;
	while (s1[i] && i < n)
		i++;
	if (!(alloc = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (s1[i] && i < n)
	{
		alloc[i] = s1[i];
		i++;
	}
	alloc[i] = 0;
	printf("\nn = %d\ns1[n] = |%c|\ns1 = |%s|\nalloc = |%s|\n", n, s1[n], s1, alloc);
	return (alloc);
}
