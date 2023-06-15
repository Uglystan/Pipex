/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:41:40 by lgirault          #+#    #+#             */
/*   Updated: 2023/03/04 17:03:06 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft_tot/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>

typedef struct s_tab
{
	int	i;
	int	j;
	int	k;
}	t_tab;

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
	char	**options;
	int		wpid;
	int		off;
	int		*pid;
	int		nbr_cmd;
	int		*pipefd;
	int		fd_infile;
	int		fd_outfile;
	int		i;
}	t_cmd;

char	*find_good_path(char **envp, char *cmd, t_cmd *cmd1);
char	**tab_option(char *cmd);
char	**make_tab_path(char **envp, char *cmd, t_cmd *cmd1);
void	error_management(int code_error, t_cmd *cmd);
void	free_tab(char **tab_path);
void	free_cmd(t_cmd *cmd);
void	last_cmd(t_cmd *cmd, char **envp, char **argv, int argc);
void	free_cmd2(t_cmd *cmd);
void	here_doc(int argc, char **argv, t_cmd *cmd);
void	close_all(t_cmd *cmd);
int		ft_strcmp_n(char *str1, char *str2);
void	redir(int start, int end, t_cmd *cmd);
void	free_cmd1(t_cmd *cmd);
void	file_error(t_cmd *cmd, int code_error);
void	close_fd(t_cmd *cmd);
void	init_tab(t_cmd *cmd);
int		first_space(char *cmd);
int		last_letter(char *cmd);
int		where(char *cmd);
void	find_path(t_cmd *cmd, char **envp, char **argv);

#endif