/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:58:19 by micheng           #+#    #+#             */
/*   Updated: 2023/08/12 17:55:31 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	print_clues(t_vars *vars)
{
	int	i = -1;
	while (++i < vars->grid_size)
	{
		ft_printf("%d", vars->edge_clues[i]);
	}
	ft_printf("\n\n");
}

void display_edge_clue_table(t_vars *vars)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < vars->grid_len)
		{
			ft_putnbr(vars->edge_clue_table[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

// void	print_grid_len(t_vars *vars)
// {
// 	int	i = -1;
// 	while (++i < vars->grid_len)
// 		ft_printf("%d", vars->tower_range[i]);
// 	write(1, "\n", 1);
// }

void	print_static_list(t_static *head)
{
	t_static *current = head;
	ft_printf("Static List: ");
	while (current != NULL)
	{
		ft_printf("(%d, %d) ", current->y, current->x);
		current = current->next;
	}
}