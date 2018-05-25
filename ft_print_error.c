/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:00:30 by vkravets          #+#    #+#             */
/*   Updated: 2018/04/01 20:00:33 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_sub_print_error_two(t_data *data)
{
	if (data->error > 0)
	{
		if (data->error == 15)
			ft_printf("ERROR : After ##start must be rooms\n");
		else if (data->error == 16)
			ft_printf("ERROR : After ##end must be rooms\n");
		else if (data->error == 17)
			ft_printf("ERROR : Before the rooms must be number of ants\n");
		else if (data->error == 18)
			ft_printf("ERROR : Empty line\n");
		else if (data->error == 21)
			ft_printf("ERROR : The map is empty\n");
		else if (data->error == 22)
			ft_printf("ERROR : No start\n");
		else if (data->error == 23)
			ft_printf("ERROR : No end\n");
		else if (data->error == 24)
			ft_printf("ERROR : No start room\n");
		else if (data->error == 25)
			ft_printf("ERROR : No end room\n");
		else if (data->error == 26)
			ft_printf("ERROR : There is no way from start to finish\n");
	}
}

void	ft_sub_print_error(t_data *data)
{
	if (data->error > 0)
	{
		if (data->error == 7)
			ft_printf("ERROR : Incorrect input of room parameters\n");
		else if (data->error == 8)
			ft_printf("ERROR : Room name can not start by 'L'\n");
		else if (data->error == 9)
			ft_printf("ERROR : Empty line\n");
		else if (data->error == 10)
			ft_printf("ERROR : This room name is already listed\n");
		else if (data->error == 11)
			ft_printf("ERROR : These coordinates are already given\n");
		else if (data->error == 12)
			ft_printf("ERROR : Before the links must be ##start && ##end\n");
		else if (data->error == 13)
			ft_printf("ERROR : After ##start && ##end must be rooms \n");
		else if (data->error == 14)
			ft_printf("ERROR : Incorrect links\n");
	}
}

void	ft_print_error(t_data *data)
{
	if (data->error > 0)
	{
		ft_printf("-----------------------------------------------|\n");
		if (data->error == 1)
			ft_printf("ERROR : Invalid number of ants\n");
		else if (data->error == 2)
			ft_printf("ERROR : Start redefined\n");
		else if (data->error == 3)
			ft_printf("ERROR : End redefined\n");
		else if (data->error == 4)
			ft_printf("ERROR : The number of ants has already been set\n");
		else if (data->error == 5)
			ft_printf("ERROR : Bad ant number\n");
		else if (data->error == 6)
			ft_printf("ERROR : Ants need to be set before ##start_room\n");
		ft_sub_print_error(data);
		ft_sub_print_error_two(data);
		ft_printf("-----------------------------------------------|\n");
	}
}
