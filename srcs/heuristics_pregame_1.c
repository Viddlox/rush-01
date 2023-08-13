/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics_pregame_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:55:10 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 05:45:09 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	lo_hi(t_vars *vars, int x, int y)
{
	if (y == 0 && vars->edge_clue_table[0][x] == 1)
	{
		vars->grid[y][x] = vars->grid_len;
		return (1);
	}
	else if (y == vars->grid_len - 1 && vars->edge_clue_table[1][x] == 1)
	{
		vars->grid[y][x] = vars->grid_len;
		return (1);
	}
	if (x == 0 && vars->edge_clue_table[2][y] == 1)
	{
		vars->grid[y][x] = vars->grid_len;
		return (1);
	}
	else if (x == vars->grid_len - 1 && vars->edge_clue_table[3][y] == 1)
	{
		vars->grid[y][x] = vars->grid_len;
		return (1);
	}
	return (0);
}

static void	check_set_lo_hi_1(t_vars *vars, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (pos->x < vars->grid_len - 1)
	{
		if (lo_hi(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->x++;
	}
	pos->x = 0;
	pos->y = vars->grid_len - 1;
	while (pos->x < vars->grid_len)
	{
		if (lo_hi(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->x++;
	}
}

static void	check_set_lo_hi_2(t_vars *vars, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (pos->y < vars->grid_len - 1)
	{
		if (lo_hi(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->y++;
	}
	pos->x = vars->grid_len - 1;
	pos->y = 0;
	while (pos->y < vars->grid_len - 1)
	{
		if (lo_hi(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->y++;
	}
}

void	heuristic_check_start(t_vars *vars, t_pos *pos)
{
	check_set_lo_hi_1(vars, pos);
	check_set_lo_hi_2(vars, pos);
	check_set_hi_lo_1(vars, pos);
	check_set_hi_lo_2(vars, pos);
}
