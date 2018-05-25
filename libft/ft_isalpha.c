/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:08:08 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/01 21:08:10 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((0x41 <= c && c <= 0x5A) || (0x61 <= c && c <= 0x7A))
		return (1);
	else
		return (0);
}
