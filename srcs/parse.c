/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:39:13 by cvine             #+#    #+#             */
/*   Updated: 2022/01/22 11:55:31 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}

char	*get_paths(char **envp)
{
	while (ft_strncmp(*envp, "PATH=", 5) && *envp)
		(*envp)++;
	return (*envp + 5);
}

char	*find_path(char **envp, char *argv)
{
	char	**path_lst;
	char	*tmp;

	path_lst = ft_split(get_paths(envp), ':');
	while (*path_lst)
	{
		tmp = ft_strjoin(*path_lst, "/");
		tmp = ft_strjoin(tmp, *get_cmd(argv));
		if (!access(tmp, F_OK | X_OK))
			return (tmp);
		free(tmp);
		path_lst++;
	}
	cmd_error(argv);
	return (NULL);
}
