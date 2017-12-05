/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:48:40 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/05 18:03:43 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	LEM_IN_H
# define LEM_IN_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct	s_list
{
	char		*name;
	int			x;
	int			y;
	struct		s_list* next;
}				t_list;

typedef struct	g_list
{
	char		*data;
	struct		g_list* next;
}				l_list;

#endif
