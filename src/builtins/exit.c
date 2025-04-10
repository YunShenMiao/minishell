/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyang <xueyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:21:25 by xueyang           #+#    #+#             */
/*   Updated: 2025/04/03 16:43:10 by xueyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//need to check whether exit is a command or a word, a file... (pwd exit, pwd >> exit)
//need to free everything before exit!!!
int	ft_exit(t_token *current)
{
	if (current->type == TOK_COMMAND)
	{
		// gc_free_all(gc);
		exit(EXIT_SUCCESS);
	}

}
