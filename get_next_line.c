/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 21:42:56 by vkravets          #+#    #+#             */
/*   Updated: 2017/12/27 21:43:05 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list			*get_file(t_list *start, int fd)
{
	t_list *save;
	t_list *tmp;

	tmp = start;
	while (start && (int)start->content_size != fd)
	{
		save = start;
		start = start->next;
	}
	if (!start)
	{
		start = ft_lstnew("\0", fd);
		start->content_size = fd;
	}
	if (save && start != tmp)
	{
		save->next = start->next;
		start->next = tmp;
	}
	return (start);
}

static	char	*ft_fjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	str = (char*)malloc(sizeof(char*) * len + 1);
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0' && *s2 != '\n')
	{
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}

static	int		ft_record(char *buff, t_list *start, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(*line);
	ft_strdel(line);
	if (ft_strchr(buff, '\n'))
	{
		while (buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			*line = ft_fjoin(temp, buff);
			start->content = ft_strsub(buff, i + 1, ft_strlen(&buff[i + 1]));
			ft_strdel(&temp);
			return (1);
		}
	}
	*line = ft_strjoin(temp, buff);
	ft_strdel(&temp);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				value;
	static	t_list	*start;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	start = get_file(start, fd);
	if (start->content && ft_record(start->content, start, line))
		return (1);
	ft_memdel(&start->content);
	while ((value = read(fd, buff, BUFF_SIZE)))
	{
		buff[value] = '\0';
		if (ft_record(buff, start, line))
			return (1);
	}
	if (**line)
		return (1);
	return (0);
}
