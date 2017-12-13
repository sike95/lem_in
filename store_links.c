/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:47:23 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 11:35:58 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	insert(t_rooms **head, char *str, char *x, char *y)
{
	t_rooms		*temp;

	temp = (t_rooms*)malloc(sizeof(t_rooms));
	temp->name = ft_strdup(str);
	temp->x = ft_atoi(x);
	temp->y = ft_atoi(y);
	temp->next = (*head);
	(*head) = temp;
}

void	insert2(t_links **node, char *room1, char *room2)
{
	t_links		*temp;

	temp = (t_links*)malloc(sizeof(t_links));
	temp->room1 = ft_strdup(room1);
	temp->room2 = ft_strdup(room2);
	temp->vis = 0;
	temp->next = (*node);
	(*node) = temp;
}

void	insert3(t_path **node, char *data)
{
	t_path		*temp;

	temp = (t_path*)malloc(sizeof(t_path));
	temp->data = ft_strdup(data);
	temp->next = *node;
	*node = temp;
}

void	insert4(t_erooms **node, char *data)
{
	t_erooms	*temp;

	temp = (t_erooms*)malloc(sizeof(t_erooms));
	temp->data = ft_strdup(data);
	temp->next = *node;
	*node = temp;
}
