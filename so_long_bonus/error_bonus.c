/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:55:47 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:55:55 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	free (data->join);
	free(data);
	exit(1);
}

int	close_win(t_long *data)
{
	free_memory(data->map);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	ft_putstr_fd("YOU QUIT", 1);
	exit(0);
	return (0);
}
