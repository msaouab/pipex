/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:29:02 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/16 20:00:22 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_child_1(int fds[2], char *path, char **av, char **env)
{
	char	*check_cmd1;
	char	**cmd1;
	int		pid1;
	int		fd;

	check_cmd1 = ft_check_cmd(path, &av[2]);
	if (!check_cmd1)
		strerror(errno);
	cmd1 = ft_split(av[2], ' ');
	pid1 = fork();
	if (pid1 == -1)
		strerror(pid1);
	if (pid1 == 0)
	{
		fd = open(av[1], O_CREAT | O_APPEND | O_RDWR, 0777);
		dup2(fd, 0);
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		close(fd);
		execve(check_cmd1, cmd1, env);
	}
	return (pid1);
}

int	ft_child_2(int fds[2], char *path, char **av, char **env)
{
	char	*check_cmd2;
	char	**cmd2;
	int		pid2;
	int		fd;

	check_cmd2 = ft_check_cmd(path, &av[3]);
	cmd2 = ft_split(av[3], ' ');
	pid2 = fork();
	if (pid2 == -1)
		strerror(pid2);
	if (pid2 == 0)
	{
		fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		dup2(fd, 1);
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		close(fd);
		execve(check_cmd2, cmd2, env);
	}
	return (pid2);
}
