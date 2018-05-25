/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:20:02 by vkravets          #+#    #+#             */
/*   Updated: 2018/04/17 17:20:05 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms	*new_list(t_rooms *lst)
{
	t_rooms *new;

	new = ft_memalloc(sizeof(t_rooms));
	new->next = NULL;
	new->next_link = NULL;
	new->prev = NULL;
	if (lst->name)
		new->name = ft_strdup(lst->name);
	else
		new->name = NULL;
	new->x = lst->x;
	new->y = lst->y;
	new->status = lst->status;
	new->set = lst->set;
	new->set_rec = lst->set_rec;
	new->is_way = lst->is_way;
	new->status = lst->status;
	new->id_ants = lst->id_ants;
	return (new);
}

void	lst_back(t_rooms **alst, t_rooms *new)
{
	t_rooms	*tmp;

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
		new->prev = tmp;
	}
}

int		ft_atoi_mod(const char *str, t_data *data)
{
	unsigned long long	n;
	unsigned long long	nt;
	int					neg;

	neg = 0;
	n = 0;
	if ((*str != '\0' && *str != 45 && *str != 43) &&
		(*str < 48 || *str > 57))
		data->error = 7;
	(*str == '-') ? neg = -1 : 0;
	(*str == '+') ? neg = 1 : 0;
	(neg != 0) ? str++ : str;
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		nt = (n * 10) + (*str - 48);
		n = (n * 10) + (*str - 48);
		str++;
	}
	if ((*str != '\0' && *str != 45 && *str != 43) &&
		(*str < 48 || *str > 57))
		data->error = 7;
	if (neg != 0)
		return (neg * n);
	return ((int)n);
}

t_way	*new_list_way(t_rooms *lst)
{
	t_way	*new;
	t_rooms *copy;

	new = ft_memalloc(sizeof(t_way));
	new->next = NULL;
	new->way = NULL;
	copy = lst;
	while (copy)
	{
		lst_back(&new->way, new_list(copy));
		copy = copy->next;
	}
	return (new);
}

void	ft_free(t_rooms **begin_list)
{
	t_rooms *start;

	while (*begin_list != NULL)
	{
		start = (*begin_list)->next;
		free((*begin_list)->name);
		free(*begin_list);
		(*begin_list) = start;
	}
}
