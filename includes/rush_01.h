/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:38:21 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 10:59:34 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_01_H
# define RUSH_01_H

# include "libft.h"
# include <stdlib.h>

typedef struct s_static
{
	int					x;
	int					y;
	struct s_static		*next;
}	t_static;

typedef struct s_static_data
{
	t_static	*head;
}	t_static_data;

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

//grid_size (total number of tower cells)
//edge_clue_table (table for array of each clue edge)
//grid_len (length of each row/col)

typedef struct s_vars
{
	int				input;
	int				*edge_clues;
	int				**grid;
	int				grid_size;
	int				grid_len;
	int				**edge_clue_table;
	t_pos			*pos;
	t_static_data	*head_static;
}	t_vars;

//grid initialization functions
int		check(int ac, char **av, t_vars *vars);
void	flood_fill(t_vars *vars);
void	grid_size(int av_len, t_vars *vars);
void	edge_clue_table_init(t_vars *vars);

//printer functions
void	display_solution(t_vars *vars);

//pregame heuristic functions
void	heuristic_check_start(t_vars *vars, t_pos *pos);
void	check_set_hi_lo_1(t_vars *vars, t_pos *pos);
void	check_set_hi_lo_2(t_vars *vars, t_pos *pos);
int		hi_lo(t_vars *vars, int x, int y);
int		hi_lo_top_bottom(t_vars *vars, int x, int y);
int		hi_lo_bottom_top(t_vars *vars, int x, int y);
int		hi_lo_left_right(t_vars *vars, int x, int y);
int		hi_lo_right_left(t_vars *vars, int x, int y);

//main game brute force functions
int		check_cases(t_vars *vars, int x, int y);

//main game heuristic functions
int		check_static(t_vars *vars, int x, int y);
int		check_duplicates(t_vars *vars, int x, int y);

//heuristic utils
void	add_static_nodes(t_vars *vars, int x, int y);
void	init_static_list(t_vars *vars, t_static_data **data);
void	set_static_nodes(t_vars *vars);
void	clear_static_data(t_static_data **data);

//testing functions
void	print_clues(t_vars *vars);
void	print_grid(int **grid, int grid_len);
void	display_edge_clue_table(t_vars *vars);
void	print_grid_len(t_vars *vars);
void	print_static_list(t_static *head);

#endif