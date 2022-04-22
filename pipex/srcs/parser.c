/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:39:13 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 17:24:34 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}

char	*get_all_paths(char **envp)
{
	while (ft_strncmp(*envp, "PATH=", 5) && *envp)
		(*envp)++;
	return (*envp + 5);
}

char	*cmd_path(char **envp, char *argv)
{
	char	**all_paths;
	char	*path;

	all_paths = ft_split(get_all_paths(envp), ':');
	while (*all_paths)
	{
		path = ft_strjoin(*all_paths, "/");
		path = ft_strjoin(path, *get_cmd(argv));
		if (!access(path, F_OK | X_OK))
			return (path);
		free(path);
		all_paths++;
	}
	cmd_error(argv);
	return (NULL);
}
