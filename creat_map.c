/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:51:33 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:51:42 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_image_to_letter(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			image_window(data, &i, &j);
			j++;
		}
		i++;
	}
	return (0);
}

void	put_image(t_long *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "image/wall.xpm",
			&data->x, &data->y);
	data->player = mlx_xpm_file_to_image(data->mlx, "image/player.xpm",
			&data->x, &data->y);
	data->exit = mlx_xpm_file_to_image(data->mlx, "image/exit.xpm",
			&data->x, &data->y);
	data->collect = mlx_xpm_file_to_image(data->mlx, "image/collect.xpm",
			&data->x, &data->y);
	data->back = mlx_xpm_file_to_image(data->mlx, "image/back.xpm",
			&data->x, &data->y);
}

int	creat_map(t_long *data)
{
	data->length = check_wall(data) + 1;
	data->width = ft_strlen(data->map[0]);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, 50 * data->width,
			50 * data->length, "Super_Mario");
	if (!data->win)
	{
		free(data->mlx);
		return (0);
	}
	put_image(data);
	put_image_to_letter(data);
	mlx_hook (data->win, 2, 0, &move_player, data);
	mlx_hook (data->win, 17, 0, close_win, data);
	mlx_loop_hook (data->mlx, &put_image_to_letter, data);
	mlx_loop(data->mlx);
	return (0);
}
