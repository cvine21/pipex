/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:59:23 by cvine             #+#    #+#             */
/*   Updated: 2022/04/19 22:41:15 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	pipex(int infile, int outfile, char **argv, char **envp)
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
	exit (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (argc < 5)
		return (1);
	infile = open(argv[1], O_RDONLY);
	check_fd(infile, argv[1]);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	check_fd(outfile, argv[4]);
	pipex(infile, outfile, argv, envp);
	return (0);
}
