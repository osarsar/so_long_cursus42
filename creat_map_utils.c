/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:51:59 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:52:04 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
