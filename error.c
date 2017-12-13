/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:50:26 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 11:15:34 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		error_check(t_main *var)
{
	while (var->index)
	{
		if (!(ft_strcmp(var->index->line, "##start")))
		{
			var->split = ft_strsplit(var->index->next->line, ' ');
			var->start = var->split[0];
			var->has_start = 1;
		}
		if (!(ft_strcmp(var->index->line, "##end")))
		{
			var->split = ft_strsplit(var->index->next->line, ' ');
			var->end = var->split[0];
			var->has_end = 1;
		}
		var->index = var->index->next;
	}
	if (!var->has_start || !var->has_end)
	{
		ft_putstr("***************************************************\n");
		ft_putstr("Invalid map: No start/end \n");
		ft_putstr("***************************************************\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}
