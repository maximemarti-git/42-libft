/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:57:11 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/02 09:36:08 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_line(int fd, char *stash, char *buffer)
{
	int		byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(stash), (NULL));
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract_line(char *line)
{
	char	*new_stash;
	size_t	index;

	index = 0;
	while (line[index] && line[index] != '\n')
		index++;
	if (!line[index])
		return (NULL);
	new_stash = ft_substr(line, index + 1, ft_strlen(line) - index);
	if (*new_stash == 0)
	{
		free(new_stash);
		new_stash = NULL;
	}
	line[index + 1] = 0;
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_HARD_LIMIT];
	char		*line;
	char		*buffer;

	if ((fd < 0 || fd > FD_HARD_LIMIT) || BUFFER_SIZE <= 0
		|| read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, stash[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash[fd] = extract_line(line);
	return (line);
}