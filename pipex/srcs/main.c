/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:23:52 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 17:27:28 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	execute_cmd(infile, outfile, argv, envp);
	return (0);
}