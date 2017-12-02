/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:51:28 by llopez            #+#    #+#             */
/*   Updated: 2017/12/02 18:06:37 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_break(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (i - 1);
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	int			i_buff;
	char		line_read[BUFF_SIZE + 1];
	static char *buff;
	char		*tmp;
	int			break_found;

	if (buff != NULL)
	{
		if (find_break(buff) > -1)
		{
			break_found = find_break(buff);
			*line = ft_strnew((size_t)break_found);
			ft_strncpy(*line, buff, (size_t)break_found);
			tmp = ft_strnew(ft_strlen(buff) - break_found);
			tmp = ft_strsub(buff, (break_found + 1), \
					(ft_strlen(buff) - (break_found + 1)));
			free(buff);
			buff = ft_strnew(ft_strlen(tmp));
			ft_strcpy(buff, tmp);
			free(tmp);
			return (1);
		}
		else{
			*line = ft_strnew(ft_strlen(buff));
			*line = ft_strsub(buff, 1, ft_strlen(buff) - 1);
		}
	}
	else {
		buff = ft_strnew(0);
	}
	*line = ft_strnew(0);
	line_read[BUFF_SIZE] = '\0';
	while ((i_buff = read(fd, line_read, BUFF_SIZE)) > 0)
	{
		printf("line_read : %s\n", line_read);
		if (find_break(line_read) > -1)
		{
			tmp = ft_strnew(ft_strlen(*line));
			ft_strcpy(tmp, *line);
			free(*line);
			*line = ft_strnew(ft_strlen(*line) + ft_strlen(buff));
			ft_strcpy(*line, tmp);
			*line = ft_strncat(*line, line_read, (size_t)find_break(line_read));
			buff = ft_strsub(line_read, find_break(line_read)+1, (BUFF_SIZE \
					- find_break(line_read)));
			break;
		}
		else {
			tmp = ft_strnew(ft_strlen(*line));
			ft_strcpy(tmp, *line);
			free(*line);
			*line = ft_strnew(ft_strlen(*line) + ft_strlen(buff));
			ft_strcpy(*line, tmp);
			*line = ft_strcat(*line, line_read);
		}
	}
	if (i_buff == 0)
		return (0);
	return (1);
}
