/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/19 22:22:35 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipe_error(void)
{
	perror("pipe opening error");
	exit(1);
}

void	check_pid(int id)
{
	if (id < 0)
	{
		perror("Fork error");
		exit(1);
	}
}

void	dup_error(int pid)
{
	if (!pid)
		perror("Issue with running dup2 in child");
	else
		perror("Issue with running dup2 in parent");
	exit(1);
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

void	cmd_error(char *argv)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(*get_cmd(argv), 2);
}
