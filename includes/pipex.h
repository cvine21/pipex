/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:05 by cvine             #+#    #+#             */
/*   Updated: 2022/01/22 11:57:33 by cvine            ###   ########.fr       */
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

char	*find_path(char **envp, char *argv);
char	*get_paths(char **envp);
char	**get_cmd(char *argv);

void	pipe_error(void);
void	check_fd(int fd, char *argv);
void	check_id(int id);
void	dup_error(int pid);
void	cmd_error(char *argv);

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif