/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:36 by rrouille          #+#    #+#             */
/*   Updated: 2022/12/02 15:53:03 by rrouille         ###   ########.fr       */
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

}

/**
* @notice	This function is using read() to add characters by characters to
*			the stash.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	prepare_stash()
{

}

/**
* @notice	This functions adds the content of the buffer to the end of the
*			stash.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
static void	add_to_stash()
{

}

/**
* @notice	This function write the entire line by searching the '\n' in
*			the stash.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	extract_line()
{
	
}

/**
* @notice	This function cleans the stash. Only the characters not in the
*			line will be ignored.
* @dev		
* @param				.
* @return	void		No parameter needed.
*/
void	clean_stash()
{
	
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
