/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics_pregame_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 05:37:01 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 10:54:05 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	hi_lo(t_vars *vars, int x, int y)
{
	if (y == 0 && vars->edge_clue_table[0][x] == vars->grid_len)
	{
		return (hi_lo_top_bottom(vars, x, y));
	}
	else if (y == vars->grid_len - 1 && vars->edge_clue_table[1][x]
		== vars->grid_len)
	{
		return (hi_lo_bottom_top(vars, x, y));
	}
	else if (x == 0 && vars->edge_clue_table[2][y] == vars->grid_len)
	{
		return (hi_lo_left_right(vars, x, y));
	}
	else if (x == vars->grid_len - 1 && vars->edge_clue_table[3][y]
		== vars->grid_len)
	{
		return (hi_lo_right_left(vars, x, y));
	}
	return (0);
}

void	check_set_hi_lo_1(t_vars *vars, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (pos->x < vars->grid_len - 1)
	{
		hi_lo(vars, pos->x, pos->y);
		pos->x++;
	}
	pos->x = 0;
	pos->y = vars->grid_len - 1;
	while (pos->x < vars->grid_len)
	{
		hi_lo(vars, pos->x, pos->y);
		pos->x++;
	}
}

void	check_set_hi_lo_2(t_vars *vars, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (pos->y < vars->grid_len - 1)
	{
		hi_lo(vars, pos->x, pos->y);
		pos->y++;
	}
	pos->x = vars->grid_len - 1;
	pos->y = 0;
	while (pos->y < vars->grid_len - 1)
	{
		hi_lo(vars, pos->x, pos->y);
		pos->y++;
	}
}