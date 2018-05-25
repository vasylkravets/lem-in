/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_link.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 21:04:02 by vkravets          #+#    #+#             */
/*   Updated: 2018/05/05 21:04:43 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_pushback(t_links **alst, t_links *new)
{
	t_links	*tmp;

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

void	free_mas(char **mas)
{
	int i;

	i = 0;
	while (mas[i])
		free(mas[i++]);
	free(mas);
}

int		check_invalid_link(t_data *data)
{
	if (data->ants != -1 && data->start != -1 &&
		data->end != -1 && data->flag_start != -1 &&
		data->flag_end != -1)
		return (1);
	return (0);
}

int		ft_check_digit(char *line, t_data *data)
{
	size_t i;

	i = 0;
	if (ft_isdigit(line[i]))
	{
		if (!ft_sub_fun_digit_two(line, &i, data))
			return (0);
	}
	else
	{
		data->error = 5;
		return (0);
	}
	if (i < 9 && line[0] != '0')
	{
		data->ants = ft_atoi(line);
		if (!ft_sub_fun_digit(data))
			return (0);
	}
	else
		return (0);
	return (1);
}

void	ft_reset_flag(t_data *data)
{
	data->ants = -1;
	data->error = -1;
	data->start = -1;
	data->end = -1;
	data->flag = -1;
	data->flag_start = -1;
	data->flag_end = -1;
	data->value = 1;
	data->invalid_link = -1;
}
