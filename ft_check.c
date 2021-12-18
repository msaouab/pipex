/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:05:05 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/18 21:26:49 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_write(char *cmd)
{
	write(1, "error: command not found: ", 26);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	exit(0);
}

void	ft_assign(char **dst, char *src, char *to_free)
{
	*dst = src;
	free(to_free);
}

char	*ft_check_path(char **env)
{
	char	*path;
	int		len;
	int		i;

	len = ft_strlen("PATH=");
	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], len - 1) == 0)
		{
			path = ft_substr(env[i], len, ft_strlen(env[i]) - len);
			return (path);
		}
		i++;
	}
	return (0);
}

char	*ft_check_cmd(char *path, char **arg)
{
	char	**link;
	char	*cmd;
	int		i;

	i = 0;
	arg = ft_split(*arg, ' ');
	cmd = arg[0];
	arg[0] = ft_strjoin("/", arg[0]);
	link = ft_split(path, ':');
	while (link[i])
	{
		link[i] = ft_strjoin(link[i], arg[0]);
		if (access(link[i], F_OK & X_OK & R_OK) == 0)
		{
			ft_assign(link, NULL, *link);
			return (link[i]);
		}
		i++;
	}
	if (link[i] == NULL)
		ft_write(cmd);
	return (NULL);
}
