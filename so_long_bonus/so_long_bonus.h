/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:57:04 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/09 22:57:14 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
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
	char	*enemie0;
	char	*enemie1;
	char	*enemie2;
	char	*enemie3;
	char	*enemie4;
	char	*enemie5;
	char	*enemie6;
	char	*enemie7;
}t_long;

void	check_error(t_long *data);
void	check_same_line(t_long *data);
int		check_wall(t_long *data);
void	check_letter(t_long *data);
void	analyse_map(t_long *data, int i, char *str);
int		put_image_to_letter(t_long *data, int i);
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
int		affiche(t_long *data, int *str);
void	move_horizontal(t_long *data, int i, int *str);
void	move_vertical(t_long *data, int i, int *str);
void	position_player(t_long *data, int i, int j);
void	image_window(t_long *data, int *s1, int *s2);
void	image(t_long *data, int *s1, int *s2);
int		put_frame(t_long *data);
void	affiche_move(t_long *data, int *i);
void	put_image_enemy(t_long *data);
void	put_enemy(t_long *data, int i, int j, int timer);
#endif
