/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:34:34 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 11:19:59 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_file		*read_and_store(t_file *head)
{
	t_file	*index;
	t_file	*temp;
	char	*line;

	if (!head)
		head = (t_file*)malloc(sizeof(t_file));
	index = head;
	index->line_number = 1;
	index->prev = NULL;
	while (get_next_line(0, &line))
	{
		index->line = ft_strdup(line);
		index->next = (t_file*)malloc(sizeof(t_file));
		temp = index;
		index = index->next;
		index->prev = temp;
		index->line_number = index->prev->line_number + 1;
		free(line);
	}
	index = index->prev;
	free(index->next);
	index->next = NULL;
	index = head;
	return (head);
}
