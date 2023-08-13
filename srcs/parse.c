/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:41:11 by micheng           #+#    #+#             */
/*   Updated: 2023/08/12 17:56:31 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

static int	check_input(char *av, int av_len, t_vars *vars)
{
	int	i;
	int	j;
	int	spaces;

	i = 0;
	j = 0;
	spaces = 0;
	vars->edge_clues = malloc(sizeof(int) * (av_len + 1));
	if (!vars->edge_clues)
		return (0);
	while (av[i] && j <= (av_len / 2))
	{
		if (!ft_isdigit(av[i]))
			return (0);
		vars->edge_clues[j] = atoi(&av[i]);
		i++;
		if (av[i] == ' ')
			spaces++;
		i++;
		j++;
	}
	vars->grid_size = j;
	if ((av_len - spaces) % 2 == 0)
		return (1);
	return (0);
}

static int	av_len(char *av, t_vars *vars)
{
	int	i;
	int	av_len;

	i = 0;
	av_len = ft_strlen(av);
	if (av_len == 31 || av_len == 39 || av_len == 47
		|| av_len == 55 || av_len == 63
		|| av_len == 71)
	{
		grid_size(av_len, vars);
		if (check_input(av, av_len, vars))
			return (1);
	}
	return (0);
}

int	check(int ac, char **av, t_vars *vars)
{
	if (ac != 2 || !av_len(av[1], vars))
	{
		ft_printf("Error: Invalid input.\n");
		return (0);
	}
	edge_clue_table_init(vars);
	flood_fill(vars);
	return (1);
}
