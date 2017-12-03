/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:51:28 by llopez            #+#    #+#             */
/*   Updated: 2017/12/03 16:08:56 by llopez           ###   ########.fr       */
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
		{
			return (i - 1);
		}
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	int			i_buff;
	char		line_read[BUFF_SIZE + 1];
	static char *buff;
	int			break_found;

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL)
		return (-1);
	if (buff != NULL)
	{
		if (find_break(buff) > -1)
		{
			break_found = find_break(buff);
			*line = ft_strnew((size_t)break_found);
			ft_strncpy(*line, buff, (size_t)break_found);
			ft_strcpy(buff, (buff + break_found + 1));
			return (1);
		}
		else {
			*line = ft_strdup(buff);
			free(buff);
			buff = ft_strnew(0);
		}
	}
	else {
		printf("buff == NULL\n");
		buff = ft_strnew(0);
		*line = ft_strnew(0);
	}
	line_read[BUFF_SIZE] = '\0';
	while ((i_buff = read(fd, line_read, BUFF_SIZE)) > 0)
	{
		printf("lu : %d chars\n", i_buff);
		if (find_break(line_read) > -1)
		{
			break_found = find_break(line_read);
			line_read[break_found] = '\0';
			*line = ft_strjoin(*line, line_read);
			buff = ft_strnew(ft_strlen(line_read + break_found + 1));
			ft_strcpy(buff, (line_read + break_found + 1));
			return (1);
		}
		else {
			*line = ft_strjoin(*line, line_read);
		}
	}
	if (ft_strlen(*line) > 0 || i_buff > 0)
		return (1);
	return (0);
}
