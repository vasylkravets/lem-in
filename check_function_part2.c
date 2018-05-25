/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 23:05:32 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/05 23:05:34 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_room_after_start(char *line, t_data *data, t_rooms **room)
{
	t_rooms *temp;
	int		i;

	if (data->ants != -1 && ft_strequ("##end", line) && data->start == 1)
	{
		i = 0;
		temp = *room;
		while (temp)
		{
			if (data->start == 1 && temp->status == 0)
				i++;
			temp = temp->next;
		}
		if (i != 1)
		{
			data->error = 15;
			return (1);
		}
	}
	return (0);
}

int		check_room_after_end(char *line, t_data *data, t_rooms **room)
{
	t_rooms	*temp;
	int		i;

	if (data->ants != -1 && ft_strequ("##start", line) && data->end == 1)
	{
		i = 0;
		temp = *room;
		while (temp)
		{
			if (data->end == 1 && temp->status == 2)
				i++;
			temp = temp->next;
		}
		if (i != 1)
		{
			data->error = 16;
			return (1);
		}
	}
	return (0);
}

int		check_the_end(t_data *data)
{
	if (data->error > 0)
		return (1);
	if (data->value == 0)
	{
		if (data->ants == -1)
			data->error = 21;
		else if (data->start == -1)
			data->error = 22;
		else if (data->end == -1)
			data->error = 23;
		else if (data->flag_start == -1)
			data->error = 24;
		else if (data->flag_end == -1)
			data->error = 25;
		return (1);
	}
	return (0);
}

int		ft_check_list(t_rooms *queue, char *name)
{
	t_rooms *tmp;

	tmp = queue;
	while (tmp != NULL)
	{
		if (ft_strequ(tmp->name, name))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_check_dublicate(t_rooms *down, t_way *stack)
{
	t_way	*temp_stack;
	t_rooms *temp_way;
	t_rooms *temp_down;

	temp_stack = stack;
	while (temp_stack)
	{
		temp_way = temp_stack->way;
		while (temp_way)
		{
			temp_down = down;
			while (temp_down)
			{
				if (ft_strequ(temp_down->name, temp_way->name) &&
					temp_down->status != 0 && temp_down->status != 2)
					temp_stack->value = -5;
				temp_down = temp_down->next;
			}
			temp_way = temp_way->next;
		}
		temp_stack = temp_stack->next;
	}
}
