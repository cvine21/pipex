/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 11:54:13 by cvine            ###   ########.fr       */
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
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putendl_fd(*get_cmd(argv), STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	execve_error(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	perror(" execution failed");
	exit(EXIT_FAILURE);
}
