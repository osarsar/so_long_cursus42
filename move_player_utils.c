/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:30:52 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/07 14:30:54 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	affiche(int *i)
{
	*i = *i + 1;
	ft_putnbr_fd(*i, 1);
	write(1, "\n", 1);
}

void	move_horizontal(t_long *data, int touch, int *i)
{
	if (touch == 2)
	{
		if (data->map[data->i_p][data->j_p + 1] != '1')
		{
			affiche(i);
			go_right(data);
		}
	}
	else if (touch == 0)
	{
		if (data->map[data->i_p][data->j_p - 1] != '1')
		{
			affiche(i);
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
			affiche(i);
			go_up(data);
		}
	}
	else if (touch == 1)
	{
		if (data->map[data->i_p + 1][data->j_p] != '1')
		{
			affiche(i);
			go_down(data);
		}
	}
}
