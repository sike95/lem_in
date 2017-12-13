/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:48:40 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/13 12:08:03 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_links
{
	char			*room1;
	char			*room2;
	int				vis;
	struct s_links	*next;
}					t_links;

typedef struct		s_file
{
	char			*line;
	int				line_number;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

typedef	struct		s_path
{
	char			*data;
	struct s_path	*next;
}					t_path;

typedef struct		s_erooms
{
	char			*data;
	struct s_erooms	*next;
}					t_erooms;

typedef struct		s_main
{
	t_links			*links;
	t_rooms			*rooms;
	t_path			*path;
	t_erooms		*room;
	char			*ant;
	char			*line;
	int				fd;
	int				i;
	int				j;
	char			**split;
	char			*start;
	char			*end;
	t_file			*head;
	t_file			*index;
	int				has_start;
	int				has_end;
	int				num_ants;
	int				cnt;
}					t_main;

void				search(t_main *var);
int					iters(t_main *var);
int					free2d(char **str);
void				print(t_links *head);
void				insert2(t_links **node, char *room1, char *room2);
void				insert(t_rooms **head, char *str, char *x, char *y);
void				insert3(t_path **node, char *data);
int					save(t_main *var);
int					error_check(t_main *var);
t_file				*read_and_store(t_file *head);
void				print_file(t_file *head);
void				insert4(t_erooms **node, char *data);
#endif
