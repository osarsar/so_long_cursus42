/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:50:58 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:51:14 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_path(t_long *data, int i, int j)
{
	static int	exit;
	static int	collect;

	if (data->copy_map[i][j] == 'E')
	{
		exit = 1;
		return (0);
	}
	if (data->copy_map[i][j] == 'C')
		collect++;
	data->copy_map[i][j] = '1';
	if (data->copy_map[i][j + 1] != '1')
		check_valid_path(data, i, j + 1);
	if (data->copy_map[i][j - 1] != '1')
		check_valid_path(data, i, j - 1);
	if (data->copy_map[i - 1][j] != '1')
		check_valid_path(data, i - 1, j);
	if (data->copy_map[i + 1][j] != '1')
		check_valid_path(data, i + 1, j);
	if (exit == 1 && collect == data->c)
		return (1);
	return (0);
}

int	check_name_map(char *str, t_long *data)
{
	(void)*data;
	while (*str != '.')
		str++;
	str++;
	if (*str == 'b' && *(str + 1) == 'e'
		&& *(str + 2) == 'r' && *(str + 3) == '\0')
		return (0);
	ft_putstr_fd("error map", 1);
	exit(1);
}
