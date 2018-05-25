/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:03:04 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/06 00:03:05 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms	*function_for_copy_stack(t_rooms *copy)
{
	t_rooms	*tmp;
	t_rooms *new;

	new = NULL;
	tmp = copy;
	while (tmp)
	{
		lst_back(&new, new_list(tmp));
		tmp = tmp->next;
	}
	return (new);
}

t_way	*return_all_way(t_rooms *room)
{
	t_rooms *temp_room;
	t_way	*stack;

	stack = NULL;
	temp_room = room;
	while (temp_room)
	{
		if (temp_room->status == 0)
		{
			temp_room->set_rec = 1;
			stack = ft_new_mode(temp_room, room);
			break ;
		}
		temp_room = temp_room->next;
	}
	check_for_remove(stack);
	return (stack);
}

void	ft_swap_ants(t_data *data, t_way *stack, int *i)
{
	t_rooms	*temp_way;
	t_way	*temp_stack;
	int		res;

	temp_stack = stack;
	while (temp_stack)
	{
		*i += 1;
		res = data->ants - *i;
		temp_way = temp_stack->way;
		while (temp_way->next)
			temp_way = temp_way->next;
		while (temp_way->status != 0)
		{
			if (temp_way->prev->status != 0 && temp_way->prev->status)
				temp_way->id_ants = temp_way->prev->id_ants;
			else
				temp_way->id_ants = (temp_stack->value <= res) ? *i : -1;
			temp_way = temp_way->prev;
		}
		temp_stack = temp_stack->next;
	}
}

void	ft_set_id_ants(t_way *stack)
{
	t_way	*temp_stack;
	t_rooms	*down;

	temp_stack = stack;
	while (temp_stack)
	{
		down = temp_stack->way;
		while (down)
		{
			down->id_ants = -1;
			down = down->next;
		}
		temp_stack = temp_stack->next;
	}
}

int		ft_set(t_rooms *room, t_data *data, t_data *print)
{
	t_rooms	*tmp2;
	t_way	*stack;

	function_for_rec(room);
	tmp2 = room;
	while (tmp2)
	{
		if (tmp2->status == 2 && tmp2->is_way != 1)
		{
			data->error = 26;
			ft_print_error(data);
			return (1);
		}
		tmp2 = tmp2->next;
	}
	stack = return_all_way(room);
	list_remove_if_two(&stack);
	ft_check_dublicate(stack->way, stack->next);
	list_remove_if_two(&stack);
	ft_full_way(stack, data, print, room);
	free(data);
	return (0);
}
