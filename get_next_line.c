/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:51:28 by llopez            #+#    #+#             */
/*   Updated: 2017/12/13 17:44:02 by llopez           ###   ########.fr       */
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

static char		*ft_strfjoin(char *s1, char const *s2)
{
	char *alloc;

	if (!s1 || !s2)
		return (NULL);
	alloc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!alloc)
		return (NULL);
	ft_strcpy(alloc, s1);
	ft_strcpy(alloc + ft_strlen(s1), s2);
	free(s1);
	return (alloc);
}

static int		ft_fill_buff(int fd, char **line, char **buff)
{
	int			break_found;
	int			i_buff;
	char		line_read[BUFF_SIZE + 1];

	while ((i_buff = read(fd, line_read, BUFF_SIZE)) > 0)
	{
		line_read[i_buff] = '\0';
		if (find_break(line_read) > -1)
		{
			break_found = find_break(line_read);
			line_read[break_found] = '\0';
			*line = ft_strfjoin(*line, line_read);
			*buff = ft_strfjoin(*buff, (line_read + break_found + 1));
			return (1);
		}
		else
			*line = ft_strfjoin(*line, line_read);
	}
	if (ft_strlen(*line) > 0 || i_buff > 0)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff[OPEN_MAX];

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL)
		return (-1);
	if (buff[fd] != NULL)
	{
		if (find_break(buff[fd]) > -1)
		{
			*line = ft_strndup(buff[fd], find_break(buff[fd]));
			ft_strcpy(buff[fd], (buff[fd] + find_break(buff[fd]) + 1));
			return (1);
		}
		else
		{
			*line = ft_strdup(buff[fd]);
			free(buff[fd]);
			buff[fd] = ft_strnew(0);
		}
	}
	else
	{
		buff[fd] = ft_strnew(0);
		*line = ft_strnew(0);
	}
	return (ft_fill_buff(fd, line, &buff[fd]));
}
