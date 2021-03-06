/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/24 18:09:38 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_error(void)
{
	perror("pipe opening error");
	exit(EXIT_FAILURE);
}

void	check_pid(int pid)
{
	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
}

void	dup_error(int pid)
{
	if (!pid)
		perror("Issue with running dup2 in child");
	else
		perror("Issue with running dup2 in parent");
	exit(EXIT_FAILURE);
}

void	cmd_error(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putendl_fd(*cmd, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check_fd(int fd, char *argv)
{
	if (fd < 0)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putendl_fd(argv, 2);
		exit (1);
	}
}