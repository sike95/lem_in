/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:50:52 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 11:31:48 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				loop1(t_links *temp, t_erooms *temp2, t_main *var)
{
	if (ft_strcmp(var->start, temp->room2) == 0)
	{
		if (temp->vis == 0)
		{
			var->start = temp->room1;
			insert3(&var->path, var->start);
			temp->vis++;
			if (var->cnt != 2)
				iters(var);
		}
		temp2 = var->room;
		while (temp2)
		{
			if (ft_strcmp(var->start, temp2->data) == 0)
			{
				var->start = var->end;
				insert3(&var->path, var->start);
			}
			temp2 = temp2->next;
		}
		if (ft_strcmp(var->start, var->end) == 0)
			return (1);
	}
	return (0);
}

int				loop2(t_links *temp, t_erooms *temp2, t_main *var)
{
	if (temp->vis == 0)
	{
		var->start = temp->room2;
		insert3(&var->path, var->start);
		temp->vis++;
		if (var->cnt != 2)
			iters(var);
	}
	temp2 = var->room;
	while (temp2)
	{
		if (ft_strcmp(var->start, temp2->data) == 0)
		{
			var->start = var->end;
			insert3(&var->path, var->start);
		}
		temp2 = temp2->next;
	}
	if (ft_strcmp(var->start, var->end) == 0)
	{
		return (1);
	}
	return (0);
}

int				iters(t_main *var)
{
	t_links		*temp;
	t_erooms	*temp2;

	temp2 = NULL;
	temp = var->links;
	var->cnt++;
	while (temp)
	{
		if (ft_strcmp(var->start, temp->room2) == 0)
		{
			loop1(temp, temp2, var);
		}
		else if (ft_strcmp(var->start, temp->room1) == 0)
		{
			loop2(temp, temp2, var);
		}
		temp = temp->next;
	}
	if (var->start != var->end)
	{
		ft_putstr("NO VALID PATH: PLEASE TRY A DIFFERENT MAP\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void			search(t_main *var)
{
	t_links		*temp;

	var->room = NULL;
	temp = var->links;
	while (temp)
	{
		if (ft_strcmp(var->end, temp->room1) == 0)
			insert4(&var->room, temp->room2);
		else if (ft_strcmp(var->end, temp->room2) == 0)
		{
			insert4(&var->room, temp->room1);
		}
		temp = temp->next;
	}
}
