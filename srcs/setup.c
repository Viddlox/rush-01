/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:44:44 by micheng           #+#    #+#             */
/*   Updated: 2023/08/12 17:46:27 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	edge_clue_table_init(t_vars *vars)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	vars->edge_clue_table = malloc(sizeof(int *) * (vars->grid_len));
	if (!vars->edge_clue_table)
		return ;
	row = 0;
	while (row < 4)
	{
		vars->edge_clue_table[row] = malloc(sizeof(int) * vars->grid_len);
		if (!vars->edge_clue_table[row])
			return ;
		col = 0;
		while (col < vars->grid_len)
		{
			if (i < vars->grid_size)
				vars->edge_clue_table[row][col] = vars->edge_clues[i];
			col++;
			i++;
		}
		row++;
	}
	display_edge_clue_table(vars);
}

void	grid_size(int av_len, t_vars *vars)
{
	if (av_len == 31)
		vars->grid_len = 4;
	else if (av_len == 39)
		vars->grid_len = 5;
	else if (av_len == 47)
		vars->grid_len = 6;
	else if (av_len == 55)
		vars->grid_len = 7;
	else if (av_len == 63)
		vars->grid_len = 8;
	else if (av_len == 71)
		vars->grid_len = 9;
}

void	flood_fill(t_vars *vars)
{
	int	row;
	int	col;

	vars->grid = malloc(sizeof(int *) * (vars->grid_len));
	if (!vars->grid)
		return ;
	row = 0;
	while (row < vars->grid_len)
	{
		vars->grid[row] = malloc(sizeof(int) * vars->grid_len);
		if (!vars->grid[row])
			return ;
		col = 0;
		while (col < vars->grid_len)
		{
			vars->grid[row][col] = 0;
			col++;
		}
		row++;
	}
}
