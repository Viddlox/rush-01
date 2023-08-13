/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:59:52 by micheng           #+#    #+#             */
/*   Updated: 2023/08/12 15:46:39 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	check_duplicates(t_vars *vars, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (++tmp_x < vars->grid_len)
	{
		if (vars->grid[tmp_y][tmp_x] == vars->grid[y][x])
			return (1);
	}
	tmp_x = x;
	tmp_y = y;
	while (++tmp_y < vars->grid_len)
	{
		if (vars->grid[tmp_y][tmp_x] == vars->grid[y][x])
			return (1);
		++tmp_y;
	}
	return (0);
}

int	check_static(t_vars *vars, int x, int y)
{
	t_static	*current;

	current = vars->head_static->head;
	while (current != NULL)
	{
		if (vars->grid[y][x] == current->x)
			return (1);
		current = current->next;
	}
	return (0);
}