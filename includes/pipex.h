/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:05 by cvine             #+#    #+#             */
/*   Updated: 2022/04/19 23:07:44 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

char	*cmd_path(char **envp, char *argv);
char	**get_cmd(char *argv);

void	pipe_error(void);
void	check_fd(int fd, char *argv);
void	check_pid(int id);
void	dup_error(int pid);
void	cmd_error(char *argv);

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);

#endif