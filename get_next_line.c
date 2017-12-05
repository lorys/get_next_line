/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:51:28 by llopez            #+#    #+#             */
/*   Updated: 2017/12/05 11:44:10 by llopez           ###   ########.fr       */
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
	return (-1);
}

static int		ft_fill_buff(int fd, char *line, char **buff)
{
	int			break_found;
	int			i_buff;
	char		line_read[BUFF_SIZE + 1];
printf("line = %s\n", *line);
	while ((i_buff = read(fd, line_read, BUFF_SIZE)) > 0)
	{
		line_read[i_buff] = '\0';
		if (find_break(line_read) > -1)
		{
			break_found = find_break(line_read);
			line_read[break_found] = '\0';
			*line = ft_strjoin(*line, line_read);
			buff = ft_strjoin(buff, (line_read + break_found + 1));
			return (1);
		}
		else
			*line = ft_strjoin(*line, line_read);
	}
	printf("line : %s\nbuff : %s\nline_read : %s\n", *line, buff, line_read);
	if (ft_strlen(*line) > 0 || i_buff > 0)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff;

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL)
		return (-1);
	if (buff != NULL)
	{
		if (find_break(buff) > -1)
		{
			*line = ft_strndup(buff, find_break(buff));
			ft_strcpy(buff, (buff + find_break(buff) + 1));
			return (1);
		}
		else
		{
			*line = ft_strdup(buff);
			free(buff);
			buff = ft_strnew(0);
		}
	}
	else
	{
		buff = ft_strnew(0);
		*line = ft_strnew(0);
	}
	if (ft_fill_buff(fd, **line, &buff) == 1)
	{
		printf("ligne lu : %s\nbuff static : %s\n", *line, buff);
		return (1);
	}
	else
		return (0);
}
