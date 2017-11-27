/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:51:28 by llopez            #+#    #+#             */
/*   Updated: 2017/11/27 19:01:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_break(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i - 1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			i_buff;
	char		line_read[BUFF_SIZE + 1];
	char		*overflow;
	static char	*buff;

	overflow = ft_strnew(0);
	line_read[BUFF_SIZE] = '\0';
	*line = (buff == NULL) ? ft_strnew(0) : ft_strcpy(*line, buff);
	buff = (buff == NULL) ? ft_strnew(0) : buff;
	while ((i_buff = read(fd, line_read, BUFF_SIZE)) > 0)
	{
		if (find_break(line_read) == 1)
		{
			*line = ft_strncpy(*line, line_read, (size_t)find_break(line_read));
			buff = ft_strsub(line_read, find_break(line_read), (BUFF_SIZE - \
						find_break(line_read)));
			break;
		}
		else {
			*line = ft_strcat(*line, line_read);
		}
	}
	printf("%s\n", line_read);
	return (1);
}
