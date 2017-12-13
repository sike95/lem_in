/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:35:20 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 11:22:12 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		create_map(t_main *var)
{
	if (var->index->line[0] != '#')
	{
		if (!ft_strchr(var->index->line, ' ') &&
				!ft_strchr(var->index->line, '-'))
			var->num_ants = ft_atoi(var->index->line);
		else if (!ft_strchr(var->index->line, '-') &&
				ft_strchr(var->index->line, ' '))
		{
			var->split = ft_strsplit(var->index->line, ' ');
			insert((&(var->rooms)), var->split[0],
					var->split[1], var->split[2]);
			free2d(var->split);
		}
		else if (ft_strchr(var->index->line, '-'))
		{
			var->split = ft_strsplit(var->index->line, '-');
			insert2((&(var->links)), var->split[0], var->split[1]);
			free2d(var->split);
		}
	}
	return (0);
}

int		save(t_main *var)
{
	var->rooms = NULL;
	var->links = NULL;
	var->index = var->head;
	while (var->index)
	{
		create_map(var);
		ft_putendl(var->index->line);
		var->index = var->index->next;
	}
	ft_putstr("\n");
	return (0);
}
