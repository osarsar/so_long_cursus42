/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:56:13 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:56:16 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_up(t_long *data)
{	
	char	tmp;

	tmp = data->map[data->i_p][data->j_p];
	if ((data->map[data->i_p - 1][data->j_p] == 'E' && data->c == 0)
		|| data->map[data->i_p - 1][data->j_p] == 'X')
	{
		ft_putstr_fd("-------------------GAME OVER-------------------", 1);
		exit(1);
	}
	else if (data->map[data->i_p - 1][data->j_p] == 'C')
	{
		data->map[data->i_p][data->j_p] = '0';
		data->map[data->i_p - 1][data->j_p] = tmp;
		data->i_p -= 1;
		data->c--;
	}
	else if (data->map[data->i_p - 1][data->j_p] != 'E')
	{
		data->map[data->i_p][data->j_p] = data->map[data->i_p - 1][data->j_p];
		data->map[data->i_p - 1][data->j_p] = tmp;
		data->i_p -= 1;
	}
}

void	go_down(t_long *data)
{
	char	tmp;

	tmp = data->map[data->i_p][data->j_p];
	if ((data->map[data->i_p + 1][data->j_p] == 'E' && data->c == 0)
		|| data->map[data->i_p + 1][data->j_p] == 'X')
	{
		ft_putstr_fd("-------------------GAME OVER-------------------", 1);
		exit(1);
	}
	else if (data->map[data->i_p + 1][data->j_p] == 'C')
	{
		data->map[data->i_p][data->j_p] = '0';
		data->map[data->i_p + 1][data->j_p] = tmp;
		data->i_p += 1;
		data->c--;
	}
	else if (data->map[data->i_p + 1][data->j_p] != 'E')
	{
		data->map[data->i_p][data->j_p] = data->map[data->i_p + 1][data->j_p];
		data->map[data->i_p + 1][data->j_p] = tmp;
		data->i_p += 1;
	}
}

void	go_right(t_long *data)
{	
	char	tmp;

	tmp = data->map[data->i_p][data->j_p];
	if ((data->map[data->i_p][data->j_p + 1] == 'E' && data->c == 0)
		|| data->map[data->i_p][data->j_p + 1] == 'X')
	{
		ft_putstr_fd("-------------------GAME OVER-------------------", 1);
		exit(1);
	}
	else if (data->map[data->i_p][data->j_p + 1] == 'C')
	{
		data->c--;
		data->map[data->i_p][data->j_p] = '0';
		data->map[data->i_p][data->j_p + 1] = tmp;
		data->j_p += 1;
	}
	else if (data->map[data->i_p][data->j_p + 1] != 'E')
	{
		data->map[data->i_p][data->j_p] = data->map[data->i_p][data->j_p + 1];
		data->map[data->i_p][data->j_p + 1] = tmp;
		data->j_p += 1;
	}
}

void	go_left(t_long *data)
{
	char	tmp;

	tmp = data->map[data->i_p][data->j_p];
	if ((data->map[data->i_p][data->j_p - 1] == 'E' && data->c == 0)
		|| data->map[data->i_p][data->j_p - 1] == 'X')
	{
		ft_putstr_fd("-------------------GAME OVER-------------------", 1);
		exit(1);
	}
	else if (data->map[data->i_p][data->j_p - 1] == 'C')
	{
		data->map[data->i_p][data->j_p] = '0';
		data->map[data->i_p][data->j_p - 1] = tmp;
		data->j_p -= 1;
		data->c--;
	}
	else if (data->map[data->i_p][data->j_p - 1] != 'E')
	{
		data->map[data->i_p][data->j_p] = data->map[data->i_p][data->j_p - 1];
		data->map[data->i_p][data->j_p - 1] = tmp;
		data->j_p -= 1;
	}
}

int	move_player(int touch, t_long *data)
{
	static int	i;

	move_vertical(data, touch, &i);
	move_horizontal(data, touch, &i);
	if (touch == 53)
		exit(1);
	put_image_to_letter(data, i);
	return (0);
}
