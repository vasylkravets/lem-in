/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:55:10 by vkravets          #+#    #+#             */
/*   Updated: 2018/04/18 16:55:12 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstdel_func(t_rooms **alst)
{
	t_rooms *tmp;
	t_rooms *tmp_next;

	tmp = *alst;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = tmp_next;
	}
	*alst = NULL;
}

t_rooms	*sub_func_lst_add(char **mas, t_data *data)
{
	t_rooms	*tmp;

	tmp = ft_memalloc(sizeof(t_rooms));
	if (data->start == 1 && data->flag_start == -1)
	{
		tmp->status = 0;
		data->flag_start = 1;
	}
	else if (data->end == 1 && data->flag_end == -1)
	{
		tmp->status = 2;
		data->flag_end = 1;
	}
	else
		tmp->status = 1;
	tmp->name = ft_strdup(mas[0]);
	tmp->x = ft_atoi_mod(mas[1], data);
	tmp->y = ft_atoi_mod(mas[2], data);
	return (tmp);
}

t_data	*new_list_data(char *str)
{
	t_data *new;

	new = ft_memalloc(sizeof(t_data));
	new->flag = 0;
	new->ants = 0;
	new->error = 0;
	new->start = 0;
	new->end = 0;
	new->flag_start = 0;
	new->flag_end = 0;
	new->value = 0;
	new->next = NULL;
	new->line = ft_strdup(str);
	return (new);
}

void	lst_back_data(t_data **alst, t_data *new)
{
	t_data	*tmp;

	tmp = *alst;
	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	lst_back_way(t_way **alst, t_way *new)
{
	t_way	*tmp;

	tmp = *alst;
	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
