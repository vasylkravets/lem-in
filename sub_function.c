/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 22:54:58 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/05 22:55:00 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_sub_fun_digit(t_data *data)
{
	if (data->ants < 0 && data->ants != -1)
	{
		data->error = 5;
		return (0);
	}
	return (1);
}

int		ft_sub_fun_digit_two(char *line, size_t *i, t_data *data)
{
	while (ft_isdigit(line[*i]))
		(*i)++;
	if (*i != ft_strlen(line))
	{
		data->error = 5;
		return (0);
	}
	return (1);
}

t_links	*ft_search(char *down, t_rooms *room)
{
	t_rooms *temp_room;

	temp_room = room;
	while (temp_room)
	{
		if (ft_strequ(down, temp_room->name))
			return (temp_room->next_link);
		temp_room = temp_room->next;
	}
	return (NULL);
}

void	function_for_rec(t_rooms *room)
{
	t_rooms *temp_room;

	temp_room = room;
	while (temp_room)
	{
		temp_room->set_rec = -1;
		temp_room->set = -1;
		temp_room = temp_room->next;
	}
	temp_room = room;
	while (temp_room != NULL)
	{
		if (temp_room->status == 0)
			ft_recursion(temp_room->next_link, 1);
		temp_room = temp_room->next;
	}
}

int		ft_break(t_way *stack)
{
	t_way	*temp_stack;
	t_rooms *temp_way;

	temp_stack = stack;
	while (temp_stack)
	{
		temp_way = temp_stack->way->next;
		while (temp_way)
		{
			if (temp_way->id_ants != -1)
				return (1);
			temp_way = temp_way->next;
		}
		temp_stack = temp_stack->next;
	}
	return (0);
}
