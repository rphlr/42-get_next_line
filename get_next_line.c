/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:36 by rrouille          #+#    #+#             */
/*   Updated: 2022/12/05 15:19:47 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @author	rrouille
* @title	Get Next Line
* @notice	This project will not only allow you to add a very convenient
*			function to your collection, but it will also make you learn a
*			highly interesting new concept in C programming: static variables.
*/

#include "get_next_line.h"

/**
* @notice	This function is using read() to add characters by characters to
*			the stash.
* @dev		
* @param	int			The file descriptor to read from.
* @return	char *		The line that was read or NULL if ther is nothing else
*						to read or an error occurred.
*/
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	prepare_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/**
* @notice	This function is using read() to add characters by characters to
*			the stash.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	prepare_stash(int fd, t_list **stash)
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}
}

/**
* @notice	This functions adds the content of the buffer to the end of the
*			stash.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	add_to_stash(t_list **stash, char *buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

/**
* @notice	This function write the entire line by searching the '\n' in
*			the stash.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/**
* @notice	This function cleans the stash. Only the characters not in the
*			line will be ignored.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

/**
* @notice	Main function for trying get next line.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	return (0);
}
