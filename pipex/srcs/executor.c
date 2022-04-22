/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:59:23 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 17:31:40 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *fd, int infile, int outfile, int pid)
{
	close(fd[0]);
	close(outfile);
	if (dup2(infile, 0) < 0 || dup2(fd[1], 1) < 0)
		dup_error(pid);
	close(fd[1]);
	close(infile);
}

void	parent(int *fd, int infile, int outfile, int pid)
{
	wait(NULL);
	close(fd[1]);
	close(infile);
	if (dup2(fd[0], 0) < 0 || dup2(outfile, 1) < 0)
		dup_error(pid);
	close(fd[0]);
	close(outfile);
}

void	execute_cmd(int infile, int outfile, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		pipe_error();
	pid = fork();
	check_pid(pid);
	if (!pid)
	{
		child(fd, infile, outfile, pid);
		execve(cmd_path(envp, argv[2]), get_cmd(argv[2]), envp);
	}
	else
	{
		parent(fd, infile, outfile, pid);
		execve(cmd_path(envp, argv[3]), get_cmd(argv[3]), envp);
	}
	exit(EXIT_FAILURE);
}
