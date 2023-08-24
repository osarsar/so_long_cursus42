/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:53:29 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/07 17:52:09 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <stdlib.h>

typedef struct s_long
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*back;
	char	**map;
	char	**copy_map;
	char	*vect;
	char	*join;
	int		width;
	int		length;
	int		x;
	int		y;
	int		i_p;
	int		j_p;
	int		i_p_copy;
	int		j_p_copy;
	int		c;
	int		p;
	int		e;
	int		x1;
}t_long;

void	check_error(t_long *data);
void	check_same_line(t_long *data);
int		check_wall(t_long *data);
void	check_letter(t_long *data);
void	analyse_map(t_long *data, int i, char *str);
int		put_image_to_letter(t_long *data);
void	put_image(t_long *data);
void	struct_init(t_long *data);
int		creat_map(t_long *data);
int		move_player(int i, t_long *data);
int		check_valid_path(t_long *data, int i, int j);
void	go_up(t_long *data);
void	go_down(t_long *data);
void	go_left(t_long *data);
void	go_right(t_long *data);
int		check_name_map(char *str, t_long *data);
void	free_memory(char **map);
int		close_win(t_long *data);
void	quit_program(t_long *data);
void	affiche(int *str);
void	move_horizontal(t_long *data, int i, int *str);
void	move_vertical(t_long *data, int i, int *str);
void	position_player(t_long *data, int i, int j);
void	image_window(t_long *data, int *s1, int *s2);
void	image(t_long *data, int *s1, int *s2);
#endif 