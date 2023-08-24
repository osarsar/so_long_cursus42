/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:20:23 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/07 15:20:24 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(char **str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		free(str[i]);
	}
	free(str);
}

void	quit_program(t_long *data)
{
	free(data->join);
	free(data);
	exit(1);
}

int	close_win(t_long *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_putstr_fd("YOU QUIT", 1);
	exit(0);
	return (0);
}

void	position_player(t_long *data, int i, int j)
{
	data->i_p = i;
	data->j_p = j;
	data->p++;
}
