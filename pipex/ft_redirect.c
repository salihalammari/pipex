/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:48:57 by slammari          #+#    #+#             */
/*   Updated: 2022/01/20 15:35:56 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in(const char *file)
{
	int			infile;

	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		perror("open fail");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
}

void	redirect_out(const char *file)
{
	int			outfile;

	outfile = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("open fail");
		exit(1);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	connect_pipe(int fd[2], int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}

void	exe_cmd(int ac, char **argv, char **envp)
{
	char		**path;
	char		**cmd;
	char		*cmd_path;

	path = split_path(envp);
	cmd = ft_split(argv[ac], ' ');
	if ((cmd_path = get_path(path, cmd[0])) == NULL)
	{
		free_all(path, cmd, cmd_path);
		perror("command not found");
		exit(1);
	}
	if ((execve(cmd_path, cmd, envp)) == -1)
	{
		free_all(path, cmd, cmd_path);
		perror("exevc fail");
		exit(1);
	}
}
