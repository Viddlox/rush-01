/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics_pregame_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:38:39 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 10:51:13 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	hi_lo_top_bottom(t_vars *vars, int x, int y)
{
	vars->grid[y][x] = 1;
	while (++y < vars->grid_len)
		vars->grid[y][x] = vars->grid[y - 1][x] + 1;
	return (1);
}

int	hi_lo_bottom_top(t_vars *vars, int x, int y)
{
	vars->grid[y][x] = 1;
	while (--y >= 0)
		vars->grid[y][x] = vars->grid[y + 1][x] + 1;
	return (1);
}

int	hi_lo_left_right(t_vars *vars, int x, int y)
{
	vars->grid[y][x] = 1;
	while (++x < vars->grid_len)
		vars->grid[y][x] = vars->grid[y][x - 1] + 1;
	return (1);
}

int	hi_lo_right_left(t_vars *vars, int x, int y)
{
	vars->grid[y][x] = 1;
	while (--x >= 0)
		vars->grid[y][x] = vars->grid[y][x + 1] + 1;
	return (1);
}