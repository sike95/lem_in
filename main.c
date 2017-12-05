/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:46:18 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/05 18:20:19 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	insert(t_list **head, char *str, char *x, char *y)
{
	t_list* temp;
	temp = (t_list*)malloc(sizeof(t_list));
	temp->name = ft_strdup(str);
	temp->x = ft_atoi(x);
	temp->y = ft_atoi(y);
	temp->next = (*head);
	(*head) = temp;
}

void	insert2(l_list **node, char *data)
{
	l_list* temp;
	temp = (l_list*)malloc(sizeof(l_list));
 	temp->data = data;
 	temp->next = (*node);
 	(*node) = temp;
}

void	print(l_list** head)
{
	l_list* temp;

	temp = (*head);
	while (temp != NULL)
	{
		//printf("%s %d %d \n", temp->name, temp->x, temp->y);
		printf("%s ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int		free2d(char **str)
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

int		main(int ac, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		j;
	char	**split;
	t_list*	head;
	l_list* node;

	fd = open("map.txt", O_RDONLY);
	i = 0;
	j = 0;
	node = NULL;
	head = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#' && line[1] != '-')
		{
			split = ft_strsplit(line, ' ');
			insert(&head, split[0], split[1], split[2]);
			free2d(split);
		}
		else if (line[1] == '-')
		{
			insert2(&node, line);
		//	printf("%s\n", line);
		}
	}	
//	print(&head);
	print(&node);

	return (0);
}
