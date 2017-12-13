/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:46:18 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 12:11:53 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			free2d(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

t_path		*reverse(t_path *head)
{
	t_path	*current;
	t_path	*prev;
	t_path	*next;

	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return (head);
}

void		ver(t_main *var)
{
	var->i = 1;
	var->cnt = 0;
	var->head = NULL;
	var->path = NULL;
	var->head = read_and_store(var->head);
	var->index = var->head;
	var->has_start = 0;
	var->has_end = 0;
}

int			move_ants(t_main *var, t_path *temp)
{
	while (var->num_ants >= var->i)
	{
		temp = var->path;
		while (temp)
		{
			ft_putstr("L");
			ft_putnbr(var->i);
			ft_putstr("->");
			ft_putendl(temp->data);
			temp = temp->next;
		}
		var->i++;
	}
	return (0);
}

int			main(void)
{
	t_main		var;
	t_path		*temp;

	ver(&var);
	error_check(&var);
	save(&var);
	search(&var);
	insert3(&var.path, var.start);
	iters(&var);
	var.path = reverse(var.path);
	temp = var.path;
	move_ants(&var, temp);
	return (0);
}
