/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyang <xueyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:00:31 by xueyang           #+#    #+#             */
/*   Updated: 2025/03/24 14:43:44 by xueyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_arr_row(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

// char	**copy_envp(char **envp)
// {
// 	char	**envp_cpy;
// 	int		i;

// 	envp_cpy = malloc(sizeof(char *) * (count_arr_row(envp) + 1));
// 	if (!envp_cpy)
// 		return (NULL);
// 	i = 0;
// 	while (i < count_arr_row(envp))
// 	{
// 		envp_cpy[i] = ft_strdup(envp[i]);
// 		if (!envp_cpy[i])
// 		{
// 			free_array(envp_cpy);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	envp_cpy[i] = NULL;
// 	return (envp_cpy);
// }

int	find_equal(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	init_env(char **envp)
{
	t_env	*top_env;
	t_env	*new;
	char	*name;
	char	*value;
	int		i;

	name = ft_substr(envp[0], 0, find_equal(envp[0]));
	if (!name)
		return (error_general("malloc: env not initiated"));
	value = ft_substr(envp[0], find_equal(envp[0]) + 1, ft_strlen(envp[0]));
	if (!value)
		return (error_general("malloc: env not initiated"));
	top_env = create_env(name, value);
	if (!top_env)
		return (error_general("malloc: env not initiated"));
	i = 1;
	while (i < count_arr_row(envp))
	{
		name = ft_substr(envp[i], 0, find_equal(envp[i]));
		if (!name)
			return (error_general("malloc: env not initiated"));
		value = ft_substr(envp[i], find_equal(envp[i]) + 1, ft_strlen(envp[i]));
		if (!value)
			return (error_general("malloc: env not initiated"));
		new = create_env(name, value);
		if (!new)
			return (error_general("malloc: env not initiated"));
		ft_env_add_back(&top_env, new);
		i++;
	}
	return (0);
}