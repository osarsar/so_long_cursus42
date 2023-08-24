/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:50:25 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:50:28 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error(t_long *data)
{
	int	i;

	if (data->join == NULL)
	{
		free(data);
		ft_putstr_fd("Map Empty!\n", 1);
		exit(1);
	}
	if (data->join[0] == '\n')
	{
		ft_putstr_fd("Map start with new line!\n", 1);
		quit_program(data);
	}
	if (data->join[ft_strlen(data->join) - 1] != '1')
		quit_program(data);
	i = 0;
	while (data->join[i])
	{	
		if (data->join[i] != '1' && data->join[i] != '0'
			&& data->join[i] != 'C' && data->join[i] != 'P'
			&& data->join[i] != 'E' && data->join[i] != '\n')
			quit_program(data);
		i++;
	}
}

void	check_same_line(t_long *data)
{
	size_t	len;
	int		count;
	int		i;

	count = 0;
	i = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != len)
			count += 1;
		i++;
	}
	if (count != 0)
	{
		ft_putstr_fd("Map not rectangular!\n", 1);
		quit_program(data);
	}
}

int	check_wall(t_long *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			quit_program(data);
		i++;
	}
	i = 0;
	while (data->map[i])
		i++;
	i--;
	k = i;
	while (data->map[k][j])
	{
		if (data->map[k][j] != '1')
			quit_program(data);
		j++;
	}
	return (k);
}

void	check_letter(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				position_player(data, i, j);
			else if (data->map[i][j] == 'E')
				data->e++;
			else if (data->map[i][j] == 'C')
				data->c++;
			else if (data->map[i][0] != '1'
				|| data->map[i][ft_strlen(data->map[i]) - 1] != '1')
				data->x++;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->e != 1 || data->x != 0 || data->c == 0)
		quit_program(data);
}

void	analyse_map(t_long *data, int fd, char *av)
{
	data->vect = get_next_line(fd);
	while (data->vect != NULL)
	{
		if (data->join == NULL)
			data->join = ft_strdup("");
		data->join = ft_strjoin1(data->join, data->vect);
		free(data->vect);
		data->vect = get_next_line(fd);
	}
	check_name_map(av, data);
	check_error(data);
	data->map = ft_split(data->join, '\n');
	check_wall(data);
	check_same_line(data);
	check_letter(data);
	data->copy_map = ft_split(data->join, '\n');
	if (!check_valid_path(data, data->i_p, data->j_p))
		exit(1);
}
