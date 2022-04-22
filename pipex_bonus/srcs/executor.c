/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:32:50 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 11:53:01 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *fd, int pid, char *cmd, char **envp)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		dup_error(pid);
	close(fd[1]);
	execve(cmd_path(envp, cmd), get_cmd(cmd), envp);
	execve_error(cmd);
}

void	parent(int *fd, int pid)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		dup_error(pid);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

pid_t	create_child(int *fd)
{
	pid_t	pid;

	if (pipe(fd) == -1)
		pipe_error();
	pid = fork();
	check_pid(pid);
	return (pid);
}

void	create_pipes(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pid = create_child(fd);
	if (!pid)
		child(fd, pid, cmd, envp);
	else
		parent(fd, pid);
}

void	execute_cmd(int cmd_index, int argc, char **argv, char **envp, int outfile)
{
	while (cmd_index < argc - 2)
		create_pipes(argv[cmd_index++], envp);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		dup_error(1);
	close(outfile);
	execve(cmd_path(envp, argv[argc - 2]), get_cmd(argv[argc - 2]), envp);
	execve_error(argv[argc - 2]);
}