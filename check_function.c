/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:47:14 by vkravets          #+#    #+#             */
/*   Updated: 2018/04/18 16:47:16 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	func_check_ants(char *line, t_data *data)
{
	if (data->ants != -1)
	{
		data->error = 4;
		return ;
	}
	if (line[0] != '#' && !ft_check_digit(line, data))
	{
		data->error = 1;
		return ;
	}
}

int		ft_check_invalid_name(t_rooms **room, t_data *data, char **mas)
{
	t_rooms	*temp;

	temp = *room;
	while (temp)
	{
		if (ft_strequ(temp->name, mas[0]))
		{
			data->error = 10;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	sub_func_check_room(char **mas, t_data *data, t_rooms **room)
{
	t_rooms *tmp1;

	if (mas[0][0] == 'L')
	{
		data->error = 8;
		return ;
	}
	if (room)
	{
		if (ft_check_invalid_name(room, data, mas))
			return ;
		tmp1 = *room;
		while (tmp1)
		{
			if (tmp1->x == ft_atoi_mod(mas[1], data) &&
				tmp1->y == ft_atoi_mod(mas[2], data))
			{
				data->error = 11;
				return ;
			}
			tmp1 = tmp1->next;
		}
	}
}

int		ft_subfunc_check_room(char *line, t_data *data)
{
	if (ft_strchr(line, '-'))
	{
		data->error = 7;
		return (1);
	}
	if (line[0] != '#' && data->ants == -1)
	{
		data->error = 17;
		return (1);
	}
	return (0);
}

void	func_check_room(char *line, t_data *data, t_rooms **room)
{
	t_rooms	*tmp;
	char	**mas;
	int		i;

	tmp = NULL;
	i = 0;
	mas = NULL;
	if (ft_subfunc_check_room(line, data))
		return ;
	if (line[0] != '#' && line[0] != '\0')
	{
		mas = ft_strsplit(line, ' ');
		while (mas[i])
			i++;
		if (i != 3)
		{
			data->error = 7;
			return ;
		}
		sub_func_check_room(mas, data, room);
		tmp = sub_func_lst_add(mas, data);
		lst_back(room, new_list(tmp));
		ft_lstdel_func(&tmp);
		free_mas(mas);
	}
}
