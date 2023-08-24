/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:56:31 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:56:34 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	affiche(t_long *data, int *i)
{
	*i = *i + 1;
	(void)data;
	ft_putnbr_fd(*i, 1);
	write(1, "\n", 1);
	return (*i);
}

void	move_horizontal(t_long *data, int touch, int *i)
{
	if (touch == 2)
	{
		if (data->map[data->i_p][data->j_p + 1] != '1')
		{
			affiche(data, i);
			go_right(data);
		}
	}
	else if (touch == 0)
	{
		if (data->map[data->i_p][data->j_p - 1] != '1')
		{
			affiche(data, i);
			go_left(data);
		}
	}
}

void	move_vertical(t_long *data, int touch, int *i)
{
	if (touch == 13)
	{
		if (data->map[data->i_p - 1][data->j_p] != '1')
		{	
			affiche(data, i);
			go_up(data);
		}
	}
	else if (touch == 1)
	{
		if (data->map[data->i_p + 1][data->j_p] != '1')
		{
			affiche(data, i);
			go_down(data);
		}
	}
}
