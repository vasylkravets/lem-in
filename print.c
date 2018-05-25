/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:54:30 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/06 11:54:33 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_full_way(t_way *stack, t_data *data, t_data *pr, t_rooms *room)
{
	int		i;
	t_data	*temp_print;

	temp_print = pr;
	while (temp_print)
	{
		ft_printf("%s\n", temp_print->line);
		temp_print = temp_print->next;
	}
	ft_printf("\n");
	i = 0;
	ft_count_step(stack);
	ft_set_id_ants(stack);
	while (1)
	{
		ft_swap_ants(data, stack, &i);
		if (!ft_break(stack))
			break ;
		print_ants(stack);
	}
	list_remove_all(&stack, &pr, &room);
}

void	print_ants_all_in(t_data *data, t_data *print, t_rooms *room)
{
	int		i;
	t_rooms	*temp_room;
	t_data	*temp_print;

	temp_print = print;
	temp_room = room;
	while (temp_room->status != 2)
		temp_room = temp_room->next;
	while (temp_print)
	{
		ft_printf("%s\n", temp_print->line);
		temp_print = temp_print->next;
	}
	ft_printf("\n");
	i = 1;
	while (i <= data->ants)
	{
		ft_printf("L%d-%s\n", i, temp_room->name);
		i++;
	}
}

void	print_ants(t_way *stack)
{
	t_rooms	*temp_way;
	t_way	*temp_stack;
	int		var;

	var = 0;
	temp_stack = stack;
	while (temp_stack)
	{
		temp_way = temp_stack->way;
		while (temp_way->next)
			temp_way = temp_way->next;
		while (temp_way->prev)
		{
			if (temp_way->id_ants != -1)
			{
				if (var == 1)
					ft_printf(" ");
				var = 1;
				ft_printf("L%d-%s", temp_way->id_ants, temp_way->name);
			}
			temp_way = temp_way->prev;
		}
		temp_stack = temp_stack->next;
	}
	ft_printf("\n");
}

int		check_error(t_data *data, char *line)
{
	if (data->error > 0)
	{
		free(line);
		ft_print_error(data);
		return (1);
	}
	return (0);
}

int		check_hash(t_data *data)
{
	if (!check_invalid_link(data))
	{
		data->error = 7;
		return (1);
	}
	else
		data->invalid_link = 1;
	return (0);
}
