/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 22:58:58 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/05 22:58:59 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	list_remove_if_two(t_way **begin_list)
{
	t_way *start;
	t_way *tmp;

	while (*begin_list != NULL && (*begin_list)->value == -5)
	{
		start = (*begin_list)->next;
		ft_remove_down(*begin_list);
		(*begin_list) = start;
	}
	tmp = (*begin_list);
	while (tmp != NULL)
	{
		start = tmp;
		tmp = start->next;
		if (tmp != NULL && tmp->value == -5)
		{
			start->next = tmp->next;
			ft_remove_down(tmp);
			tmp = start;
		}
	}
}

void	ft_remove_down(t_way *del)
{
	t_rooms	*down;
	t_rooms	*temp;

	down = del->way;
	while (down)
	{
		temp = down;
		down = down->next;
		free(temp->name);
		free(temp);
	}
	free(del);
}

void	ft_remove_down_room(t_rooms *del)
{
	t_links	*down;
	t_links	*temp;

	down = del->next_link;
	while (down)
	{
		temp = down;
		down = down->next;
		free(temp);
	}
	free(del->name);
	free(del);
}

void	list_remove_all(t_way **begin_list, t_data **bl_pr, t_rooms **bl_r)
{
	t_way	*start;
	t_data	*tmp;
	t_rooms	*temp_room;

	while (*begin_list != NULL)
	{
		start = (*begin_list)->next;
		ft_remove_down(*begin_list);
		(*begin_list) = start;
	}
	while (*bl_pr != NULL)
	{
		tmp = (*bl_pr)->next;
		free((*bl_pr)->line);
		free(*bl_pr);
		(*bl_pr) = tmp;
	}
	while (*bl_r != NULL)
	{
		temp_room = (*bl_r)->next;
		ft_remove_down_room(*bl_r);
		(*bl_r) = temp_room;
	}
}

void	check_for_remove(t_way *stack)
{
	t_way	*temp_way;
	t_rooms	*temp_stack;
	int		i;

	temp_way = stack;
	while (temp_way)
	{
		i = 0;
		temp_stack = temp_way->way;
		while (temp_stack)
		{
			if (temp_stack->status == 0 || temp_stack->status == 2)
				i++;
			temp_stack = temp_stack->next;
		}
		if (i != 2)
			temp_way->value = -5;
		temp_way = temp_way->next;
	}
}
