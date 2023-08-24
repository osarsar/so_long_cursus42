/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:55:15 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:55:21 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_window(t_long *data, int *i, int *j)
{
	if (data->map[*i][*j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall, *j * 50, *i * 50);
	image(data, i, j);
	if (data->map[*i][*j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->back, *j * 50, *i * 50);
}

void	image(t_long *data, int *i, int *j)
{	
	if (data->map[*i][*j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->back, *j * 50, *i * 50);
		mlx_put_image_to_window(data->mlx, data->win,
			data->player, *j * 50, *i * 50);
	}
	if (data->map[*i][*j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->back, *j * 50, *i * 50);
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit, *j * 50, *i * 50);
	}	
	if (data->map[*i][*j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->back, *j * 50, *i * 50);
		mlx_put_image_to_window(data->mlx, data->win,
			data->collect, *j * 50, *i * 50);
	}
	if (data->map[*i][*j] == 'X')
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie0, *j * 50, *i * 50);
}

void	put_enemy(t_long *data, int i, int j, int timer)
{
	if (data->map[i][j] == 'X' && timer == 1000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie1, j * 50, i * 50);
	if (data->map[i][j] == 'X' && timer == 2000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie2, j * 50, i * 50);
	if (data->map[i][j] == 'X' && timer == 3000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie3, j * 50, i * 50);
	if (data->map[i][j] == 'X' && timer == 4000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie4, j * 50, i * 50);
	if (data->map[i][j] == 'X' && timer == 25000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie5, j * 50, i * 50);
	if (data->map[i][j] == 'X' && timer == 6000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie6, j * 50, i * 50);
	if (data->map[i][j] == 'X' && timer == 7000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemie7, j * 50, i * 50);
}
