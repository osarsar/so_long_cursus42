/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:54:58 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:55:04 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_image_to_letter(t_long *data, int x)
{
	int		i;
	int		j;
	char	*index;

	i = 0;
	index = ft_itoa(x);
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
	mlx_string_put(data->mlx, data->win, 10, 10, 0xccccff, "number of moves :");
	mlx_string_put(data->mlx, data->win, 200, 10, 0xccccff, index);
	free(index);
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
	put_image_enemy(data);
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
	put_image_to_letter(data, 0);
	mlx_hook (data->win, 2, 0, &move_player, data);
	mlx_hook (data->win, 17, 0, close_win, data);
	mlx_loop_hook (data->mlx, &put_frame, data);
	mlx_loop(data->mlx);
	return (0);
}

int	put_frame(t_long *data)
{
	int			i;
	int			j;
	static int	timer;

	i = 0;
	if (timer > 7000)
		timer = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_enemy(data, i, j, timer);
			j++;
		}
		i++;
	}
	timer++;
	return (0);
}

void	put_image_enemy(t_long *data)
{
		data->enemie0 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie0.xpm",
			&data->x, &data->y);
	data->enemie1 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie1.xpm",
			&data->x, &data->y);
	data->enemie2 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie2.xpm",
			&data->x, &data->y);
	data->enemie3 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie3.xpm",
			&data->x, &data->y);
	data->enemie4 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie4.xpm",
			&data->x, &data->y);
	data->enemie5 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie5.xpm",
			&data->x, &data->y);
	data->enemie6 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie6.xpm",
			&data->x, &data->y);
	data->enemie7 = mlx_xpm_file_to_image(data->mlx, "enemie/enemie7.xpm",
			&data->x, &data->y);
}
