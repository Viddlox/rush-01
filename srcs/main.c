/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:38:07 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 10:49:27 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	solve(t_vars *vars, t_pos *pos, int x, int y)
{
	int	tower_h;

	tower_h = -1;
	heuristic_check_start(vars, pos);
	display_solution(vars);
	print_static_list(vars->head_static->head);
	return (0);
	// while (++tower_h < vars->grid_len)
	// {
	// 	if (!check_duplicates(vars, x, y))
	// 	{
	// 		if (check_cases(vars, x, y) == 0)
	// 		{
	// 			if (solve(vars, pos, x + 1, y) == 1)
	// 				return (1);
	// 		}
	// 		else
	// 			vars->grid[y / vars->grid_len]
	// 			[x % vars->grid_len] = 0;
	// 	}
	// }
	// return (0);
}

void	display_solution(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	while (++y < vars->grid_len)
	{
		x = -1;
		while (++x < vars->grid_len)
		{
			ft_putnbr(vars->grid[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	t_vars		vars;
	t_pos		pos;

	vars.head_static = NULL;
	if (check(ac, av, &vars))
	{
		init_static_list(&vars, &vars.head_static);
		if (solve(&vars, &pos, 0, 0))
			display_solution(&vars);
		else
			ft_printf("Did not find any solutions.\n");
		return (0);
	}
	clear_static_data(&vars.head_static);
	return (0);
}
