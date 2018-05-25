/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:22:56 by vkravets          #+#    #+#             */
/*   Updated: 2018/04/19 16:22:58 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_valid_link(char **mas, t_data *data, t_rooms **room)
{
	t_rooms	*temp;
	int		i;

	i = 0;
	temp = *room;
	while (temp)
	{
		if (ft_strequ(mas[0], temp->name))
			i++;
		temp = temp->next;
	}
	temp = *room;
	while (temp)
	{
		if (ft_strequ(mas[1], temp->name))
			i++;
		temp = temp->next;
	}
	if (i != 2)
	{
		data->invalid_link = 1;
		free_mas(mas);
		return (1);
	}
	return (0);
}

t_links	*ft_new(char *str, t_rooms **room)
{
	t_links *new;
	t_rooms *current;

	new = ft_memalloc(sizeof(t_links));
	current = *room;
	while (current)
	{
		if (ft_strequ(current->name, str))
			new->down_room = current;
		current = current->next;
	}
	new->next = NULL;
	return (new);
}

int		ft_subfunck_check_link(t_data *data, t_rooms **room)
{
	t_rooms	*tmp;
	int		i;

	i = 0;
	if (data->end == -1 || data->start == -1)
	{
		data->error = 12;
		return (1);
	}
	tmp = *room;
	while (tmp)
	{
		if (tmp->status == 0 || tmp->status == 2)
			i++;
		tmp = tmp->next;
	}
	if (i != 2)
	{
		data->error = 13;
		return (1);
	}
	return (0);
}

void	ft_init_link(t_rooms *tmp, t_rooms **room, char **mas)
{
	int i;

	i = 0;
	while (tmp)
	{
		if (ft_strequ(tmp->name, mas[0]))
			ft_pushback(&tmp->next_link, ft_new(mas[1], room));
		tmp = tmp->next;
	}
	tmp = *room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, mas[1]))
			ft_pushback(&tmp->next_link, ft_new(mas[0], room));
		tmp = tmp->next;
	}
	while (mas[i])
		free(mas[i++]);
	free(mas);
}

void	ft_check_link(char *line, t_data *data, t_rooms **room)
{
	t_rooms	*tmp;
	char	**mas;
	int		i;

	if (ft_atoi(line) < 0 && data->ants == -1)
	{
		data->error = 1;
		return ;
	}
	if (ft_subfunck_check_link(data, room))
		return ;
	mas = ft_strsplit(line, '-');
	i = 0;
	while (mas[i])
		i++;
	if (i != 2)
	{
		data->error = 14;
		return ;
	}
	if (ft_check_valid_link(mas, data, room))
		return ;
	tmp = *room;
	ft_init_link(tmp, room, mas);
}
