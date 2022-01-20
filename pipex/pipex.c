/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:53 by slammari          #+#    #+#             */
/*   Updated: 2022/01/20 15:35:02 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **path, char **cmd, char *cmd_path)
{
	int			i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	free(cmd_path);
}

static void	child_process(int fd[2], char **argv, char **envp)
{
	redirect_in(argv[1]);
	connect_pipe(fd, STDOUT_FILENO);
	exe_cmd(2, argv, envp);
}

static void	parent_process(int fd[2], int argc, char **argv, char **envp)
{
	redirect_out(argv[argc - 1]);
	wait(0);
	connect_pipe(fd, STDIN_FILENO);
	exe_cmd(3, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	int			fd[2];

	if (argc != 5)
	{
		perror("Usage : ./pipex infile cmd1 cmd2 outfile");
		return (0);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe fail");
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork fail");
		return (0);
	}
	if (pid == 0)
		child_process(fd, argv, envp);
	else
		parent_process(fd, argc, argv, envp);
	return (0);
}
