/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:53:33 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 12:00:52 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int type)
{
	int fd;

	if (type == INFILE)
		fd = open(file, O_RDONLY);
	else if (type == OUTFILE)
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(file, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	open_file_to_append(char *file, char *limiter, int *outfile)
{
	*outfile = open_file(file, OUTFILE_HEREDOC);
	heredoc(limiter);
}

void	open_files_to_overwrite(char *in, char *out, int *outfile)
{
	int	infile;

	infile = open_file(in, INFILE);
	*outfile = open_file(out, OUTFILE);
	dup2(infile, STDIN_FILENO);
	close(infile);
}
