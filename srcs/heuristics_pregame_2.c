/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics_pregame_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 05:37:01 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 09:21:04 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	hi_lo(t_vars *vars, int x, int y)
{
	if (y == 0 && vars->edge_clue_table[0][x] == vars->grid_len)
	{
		vars->grid[y][x] = 1;
		return (1);
	}
	else if (y == vars->grid_len - 1 && vars->edge_clue_table[1][x]
		== vars->grid_len)
	{
		vars->grid[y][x] = 1;
		return (1);
	}
	else if (x == 0 && vars->edge_clue_table[2][y] == vars->grid_len)
	{
		vars->grid[y][x] = 1;
		return (1);
	}
	else if (x == vars->grid_len - 1 && vars->edge_clue_table[3][y]
		== vars->grid_len)
	{
		vars->grid[y][x] = 1;
		return (1);
	}
	return (0);
}

void	check_set_hi_lo_1(t_vars *vars, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (pos->x < vars->grid_len - 1)
	{
		if (hi_lo(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->x++;
	}
	pos->x = 0;
	pos->y = vars->grid_len - 1;
	while (pos->x < vars->grid_len)
	{
		if (hi_lo(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->x++;
	}
}

void	check_set_hi_lo_2(t_vars *vars, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (pos->y < vars->grid_len - 1)
	{
		if (hi_lo(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->y++;
	}
	pos->x = vars->grid_len - 1;
	pos->y = 0;
	while (pos->y < vars->grid_len - 1)
	{
		if (hi_lo(vars, pos->x, pos->y))
			add_static(vars, pos->x, pos->y);
		pos->y++;
	}
}