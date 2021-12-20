/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:38:21 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/20 11:21:15 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/errno.h>
# include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_check_cmd(char *path, char **av);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_check_path(char **env);
size_t	ft_strlen(const char *s);
int		ft_child_1(int fds[2], char *path, char **av, char **env);
int		ft_child_2(int fds[2], char *path, char **av, char **env);
void	ft_assign(char **dst, char *src, char *to_free);
void	*free_arr(char **arr);

#endif