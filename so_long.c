/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:19:49 by osarsar           #+#    #+#             */
/*   Updated: 2023/01/31 18:19:50 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_long *data)
{
	data->j_p = 0;
	data->i_p = 0;
	data->p = 0;
	data->e = 0;
	data->c = 0;
	data->x1 = 0;
	data->map = NULL;
	data->copy_map = NULL;
	data->width = 0;
	data->length = 0;
	data->x = 0;
	data->y = 0;
	data->j_p_copy = 0;
	data->i_p_copy = 0;
	data->join = NULL;
	data->vect = NULL;
}

int	main(int ac, char *av[])
{
	t_long	*data;
	int		fd;

	if (ac == 2)
	{
		fd = open (av[1], O_RDWR);
		data = malloc(sizeof(t_long));
		if (!data)
			return (0);
		struct_init(data);
		analyse_map(data, fd, av[1]);
		creat_map(data);
	}
}
