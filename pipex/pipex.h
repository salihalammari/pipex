/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:51:21 by slammari          #+#    #+#             */
/*   Updated: 2022/01/20 15:35:15 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
char			**split_path(char **envp);
char			*get_path(char **path, char *cmd);
void			redirect_in(const char *file);
void			redirect_out(const char *file);
void			connect_pipe(int fd[2], int io);
void			exe_cmd(int ac, char **argv, char **envp);
void			free_all(char **path, char **cmd, char *cmd_path);
int				main(int argc, char **argv, char **envp);

#endif
