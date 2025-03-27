/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:22:37 by jwardeng          #+#    #+#             */
/*   Updated: 2025/03/27 14:39:21 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_gc	*init_gc(void)
{
	int		i;
	t_gc	*gc;

	i = 0;
	gc = malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	while (i < MEM_CAT)
	{
		gc->gc_list[i] = NULL;
		i++;
	}
	return (gc);
}

void	*gc_malloc(t_gc *gc, t_mem_location category, unsigned long size)
{
	void	*ptr;
	t_garbage *new_node;

	if (!gc || category >= MEM_CAT || size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = malloc(sizeof(t_garbage));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = gc->gc_list[category];
	gc->gc_list[category] = new_node;
	return (new_node->ptr);
}

void	gc_free_category(t_gc *gc, t_mem_location category)
{
	t_garbage	*current;
	t_garbage	*temp;

	if (!gc || category >= MEM_CAT)
		return ;
	current = gc->gc_list[category];
	while (current)
	{
		if (category == TOKENS && current->ptr)
		{
			free(current->ptr);
			current->ptr = NULL;
		}
		temp = current;
		current = current->next;
		free(temp);
	}
	gc->gc_list[category] = NULL;
}

void	gc_free_all(t_gc *gc)
{
	int	i;

	i = 0;
	if (!gc)
		return ;
	while (i < MEM_CAT)
	{
		gc_free_category(gc, i);
		i++;
	}
	free(gc);
}
