/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:12:57 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 11:57:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int read_fd(char *buf)
{
	int		i;
	char	sym;
	int		read_line;

	i = 0;
	write(1, "> ", 2);
	read_line = read(0, &sym, 1);
	while (read_line && sym && sym != '\n')
	{
		if (read_line == -1)
		{
			free(buf);
			exit(EXIT_FAILURE);
		}
		buf[i++] = sym;
		read(0, &sym, 1);
	}
	buf[i++] = '\n';
	buf[i] = '\0';
	return (read_line);
}

int	get_next_line(char **str)
{
	char	*buf;
	int		read_line;

	buf = malloc(BUF_SIZE);
	if (!buf)
		exit(EXIT_FAILURE);
	*str = buf;
	read_line = read_fd(buf);
	free(buf);
	return (read_line);
}

void	heredoc(char *limiter)
{
	int		fd[2];
	char	*str;
	size_t	len;
	pid_t	pid;

	pid = create_child(fd);
	len = ft_strlen(limiter);
	if (!pid)
	{
		close(fd[0]);
		while(get_next_line(&str))
		{
			if (!strncmp(limiter, str, len) && str[len] == '\n')
				exit(EXIT_SUCCESS);
			ft_putstr_fd(str, fd[1]);
		}
		close(fd[1]);
	}
	else
		parent(fd, pid);
}