/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 23:54:55 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/05 23:54:57 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_start(char *line, t_data *data)
{
	if (ft_strequ("##start", line))
	{
		if (data->ants == -1)
		{
			data->error = 6;
			return ;
		}
		else
		{
			if (data->start == -1)
				data->start = 1;
			else
			{
				data->error = 2;
				return ;
			}
		}
	}
}

void	ft_check_end(char *line, t_data *data)
{
	if (ft_strequ("##end", line))
	{
		if (data->ants == -1)
		{
			data->error = 6;
			return ;
		}
		else
		{
			if (data->end == -1)
				data->end = 1;
			else
			{
				data->error = 3;
				return ;
			}
		}
	}
}

void	ft_recursion(t_links *current2, int i)
{
	t_links *current;

	current = current2;
	while (current != NULL)
	{
		if ((current->down_room->set == -1 || current->down_room->set > i ||
			current->down_room->status == 2) &&
			current->down_room->status != 0)
		{
			if (current->down_room->status != 2)
				current->down_room->set = i;
			else
			{
				current->down_room->set = i;
				current->down_room->is_way = 1;
			}
			ft_recursion(current->down_room->next_link, i + 1);
		}
		current = current->next;
	}
}

int		ft_check_join(t_rooms *room)
{
	t_rooms *tmp;
	t_links *temp_link;

	tmp = room;
	while (tmp)
	{
		temp_link = tmp->next_link;
		if (tmp->status == 0)
		{
			while (temp_link)
			{
				if (temp_link->down_room->status == 2)
					return (1);
				temp_link = temp_link->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_count_value(t_way *stack)
{
	t_way	*temp_stack;
	t_rooms	*down;
	int		value;
	int		suma;

	suma = 0;
	value = 1;
	temp_stack = stack;
	while (temp_stack)
	{
		down = temp_stack->way;
		suma = suma + temp_stack->step;
		temp_stack->value = (temp_stack->step * value) - suma;
		temp_stack = temp_stack->next;
		value++;
	}
}
