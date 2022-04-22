/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:59:23 by cvine             #+#    #+#             */
/*   Updated: 2022/04/22 11:41:48 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	outfile;
	int	cmd_index;

	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		if (argc < 6)
			return (1);
		cmd_index = 3;
		open_file_to_append(argv[argc - 1], argv[2], &outfile);
	}
	else
	{
		if (argc < 5)
			return (1);
		cmd_index = 2;
		open_files_to_overwrite(argv[1], argv[argc - 1], &outfile);
	}
	execute_cmd(cmd_index, argc, argv, envp, outfile);
	return (0);
}
