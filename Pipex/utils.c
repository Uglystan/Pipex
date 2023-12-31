/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:51 by lgirault          #+#    #+#             */
/*   Updated: 2023/06/15 19:18:29 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*low(char *str)
{
	int		i;
	char	*s;

	s = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (s == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'N')
			s[i] = 'n';
		else
			s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	file_error(t_cmd *cmd, int code_error)
{
	char	*test;

	if (code_error == 1)
	{
		write(2, "zsh: ", 5);
		test = low(strerror(errno));
		write(2, test, ft_strlen(test));
		write(2, ": ", 2);
		write(2, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(2, "\n", 1);
	}
	if (code_error == 9)
	{
		write(2, "zsh: ", 5);
		test = low(strerror(errno));
		write(2, test, ft_strlen(test));
		write(2, ": ", 2);
		write(2, cmd->argv[cmd->nbr_cmd + cmd->off],
			ft_strlen(cmd->argv[cmd->nbr_cmd + cmd->off]));
		write(2, "\n", 1);
	}
	free(test);
}

int	ft_strcmp_n(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			break ;
		i++;
		if (str1[i] != str2[i])
			break ;
	}
	if (i == ft_strlen(str1) && str2[i] == '\n')
		return (0);
	else
		return (1);
}

void	close_all(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < ((cmd->nbr_cmd - 1) * 2))
	{
		if (close(cmd->pipefd[i]) == -1)
			error_management(6, cmd);
		i++;
	}
}

void	redir(int start, int end, t_cmd *cmd)
{
	if (dup2(start, 0) == -1)
	{
		free_cmd1(cmd);
		exit(EXIT_FAILURE);
	}
	if (dup2(end, 1) == -1)
	{
		free_cmd1(cmd);
		exit(EXIT_FAILURE);
	}
}
