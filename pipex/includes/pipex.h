/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:05 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 17:30:31 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

void	execute_cmd(int infile, int outfile, char **argv, char **envp);

char	*cmd_path(char **envp, char *argv);
char	**get_cmd(char *argv);

void	pipe_error(void);
void	check_fd(int fd, char *argv);
void	check_pid(int id);
void	dup_error(int pid);
void	cmd_error(char *argv);

#endif