/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:53:00 by micheng           #+#    #+#             */
/*   Updated: 2023/08/13 11:01:14 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	init_static_list(t_vars *vars, t_static_data **data)
{
	*data = malloc(sizeof(t_static));
	if (*data)
		(*data)->head = NULL;
	else
	{
		ft_lstclear((t_list **)vars->head_static, &ft_del);
		return ;
	}
}

void	clear_static_data(t_static_data **data)
{
	t_static	*current;
	t_static	*temp;

	if (!data || !*data)
		return ;
	current = (*data)->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*data);
	*data = NULL;
}

void	add_static_nodes(t_vars *vars, int x, int y)
{
	t_static	*current;
	t_static	*temp;

	current = malloc(sizeof(t_static));
	if (!current)
		return ;
	current->x = x;
	current->y = y;
	current->next = NULL;
	if (vars->head_static->head == NULL)
		vars->head_static->head = current;
	else
	{
		temp = vars->head_static->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = current;
	}
}
