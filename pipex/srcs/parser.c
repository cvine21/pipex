/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:39:13 by cvine             #+#    #+#             */
/*   Updated: 2022/04/24 18:05:57 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_all_paths(char **envp)
{
	while (ft_strncmp(*envp, "PATH=", 5) && *envp)
		(*envp)++;
	return (*envp + 5);
}

char	*cmd_path(char **envp, char *argv)
{
	char	**all_paths;
	char	**cmd;
	char	*path;

	all_paths = ft_split(get_all_paths(envp), ':');
	cmd = ft_split(argv, ' ');
	while (*all_paths)
	{
		path = ft_strjoin(*all_paths, "/");
		path = ft_strjoin(path, *cmd);
		if (!access(path, F_OK | X_OK))
			return (path);
		free(path);
		all_paths++;
	}
	cmd_error(argv);
	return (NULL);
}
