/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:05 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 12:18:30 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INFILE				0
# define OUTFILE			1
# define OUTFILE_HEREDOC	2
# define BUF_SIZE			2048

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

void	open_file_to_append(char *file, char *limiter, int *outfile);
void	open_files_to_overwrite(char *in, char *out, int *outfile);
void	execute_cmd(int cmd_index, int argc, char **argv, char **envp, int outfile);
void	parent(int *fd, int pid);
void	heredoc(char *limiter);
pid_t	create_child(int *fd);

char	*cmd_path(char **envp, char *argv);
char	**get_cmd(char *argv);

void	pipe_error(void);
void	check_pid(int pid);
void	dup_error(int pid);
void	cmd_error(char *argv);
void	execve_error(char *cmd);

#endif