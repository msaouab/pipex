/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:38:19 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/16 17:14:21 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int ac, char **av, char **env)
{
	char	*path;
	int		fds[2];
	int		pid1;
	int		pid2;

	if (ac == 5)
	{
		path = ft_check_path(env);
		pipe(fds);
		pid1 = ft_child_1(fds, path, av, env);
		pid2 = ft_child_2(fds, path, av, env);
		close(fds[0]);
		close(fds[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		write(1, "Not enough args\n", 17);
	return (0);
}
