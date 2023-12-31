/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:59:56 by lgirault          #+#    #+#             */
/*   Updated: 2023/06/15 19:18:56 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_management(int code_error, t_cmd *cmd)
{
	if (code_error == 2)
		perror("Error launch child procces");
	if (code_error == 3)
		write(2, "Number argument invalid\n", 24);
	if (code_error == 4)
		perror("Error fonction dup2");
	if (code_error == 5)
		perror("Error fonction pipe");
	if (code_error == 6)
		perror ("Error fonction close");
	if (code_error == 7)
		perror ("Error fonction unlink");
	if (code_error == 8)
		perror ("Error fonction waitpid");
	if (code_error != 3)
		free_cmd1(cmd);
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab_path)
{
	int	i;

	i = 0;
	while (tab_path[i] != NULL)
	{
		free(tab_path[i]);
		i++;
	}
	free(tab_path);
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd->cmd != NULL)
		free(cmd->cmd);
	if (cmd->options != NULL)
		free_tab(cmd->options);
	if (cmd->pipefd != NULL)
		free(cmd->pipefd);
	if (cmd->pid != NULL)
		free(cmd->pid);
	exit(127);
}

void	free_cmd1(t_cmd *cmd)
{
	if (cmd->cmd != NULL)
		free(cmd->cmd);
	if (cmd->options != NULL)
		free_tab(cmd->options);
	if (cmd->pipefd != NULL)
		free(cmd->pipefd);
	if (cmd->pid != NULL)
		free(cmd->pid);
}

void	free_cmd2(t_cmd *cmd)
{
	if (cmd->cmd != NULL)
		free(cmd->cmd);
	if (cmd->options != NULL)
		free_tab(cmd->options);
	if (cmd->pipefd != NULL)
		free(cmd->pipefd);
	if (cmd->pid)
		free(cmd->pid);
	exit(0);
}
