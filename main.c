/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:31:19 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/31 13:33:45 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_all_check(char *line, t_data *data, t_rooms **room)
{
	if (check_room_after_start(line, data, room) ||
		check_room_after_end(line, data, room))
		return ;
	if (ft_isdigit(line[0]) && data->start == -1 && !ft_strchr(line, ' '))
		func_check_ants(line, data);
	else if (ft_strequ("##start", line))
		ft_check_start(line, data);
	else if (ft_strequ("##end", line))
		ft_check_end(line, data);
	else if (ft_strchr(line, ' '))
		func_check_room(line, data, room);
	else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
		ft_check_link(line, data, room);
	else if (data->ants == -1 && line[0] != '#')
		data->error = 1;
	else if (line[0] != '#' && data->value == 1)
	{
		check_hash(data);
		return ;
	}
	else if (line[0] == '\0' && data->value == 1)
		data->error = 18;
	else if (check_the_end(data))
		return ;
}

void	heart_algo(t_links *return_list, t_rooms *next_stack, t_way *stack)
{
	if (return_list->down_room->set_rec != 1)
	{
		next_stack = function_for_copy_stack(stack->way);
		lst_back(&next_stack, new_list(return_list->down_room));
		lst_back_way(&stack, new_list_way(next_stack));
		ft_free(&next_stack);
		if (return_list->down_room->status != 2)
			return_list->down_room->set_rec = 1;
	}
}

t_way	*ft_new_mode(t_rooms *new, t_rooms *room)
{
	t_way	*stack;
	t_way	*temp_stack;
	t_links *return_list;
	t_rooms *next_stack;
	t_rooms *stack_down;

	next_stack = NULL;
	stack = ft_memalloc(sizeof(t_way));
	temp_stack = stack;
	lst_back(&stack->way, new_list(new));
	while (stack != NULL)
	{
		stack_down = stack->way;
		while (stack_down->next != NULL)
			stack_down = stack_down->next;
		return_list = ft_search(stack_down->name, room);
		while (return_list != NULL)
		{
			heart_algo(return_list, next_stack, stack);
			return_list = return_list->next;
		}
		stack = stack->next;
	}
	return (temp_stack);
}

void	ft_count_step(t_way *stack)
{
	t_way	*temp_stack;
	t_rooms	*down;
	int		step;

	temp_stack = stack;
	while (temp_stack)
	{
		step = 0;
		down = temp_stack->way;
		while (down)
		{
			step++;
			down = down->next;
		}
		temp_stack->step = step;
		temp_stack->value = 0;
		temp_stack = temp_stack->next;
	}
	ft_count_value(stack);
}

int		main(void)
{
	char	*line;
	t_data	*data;
	t_data	*print;
	t_rooms *room;

	print = NULL;
	line = NULL;
	room = NULL;
	ft_reset_flag(data = ft_memalloc(sizeof(t_data)));
	while (data->value != 0)
	{
		data->value = get_next_line(0, &line);
		ft_all_check(line, data, &room);
		if (check_error(data, line))
			return (0);
		if (data->invalid_link == 1)
			break ;
		lst_back_data(&print, new_list_data(line));
		free(line);
	}
	if (ft_check_join(room))
		print_ants_all_in(data, print, room);
	else
		ft_set(room, data, print);
	return (0);
}
