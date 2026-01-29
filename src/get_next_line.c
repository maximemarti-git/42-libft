/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:57:11 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 16:09:30 by mamarti          ###   ########.fr       */
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

void	gnl_clear(int fd)
{
	if (fd < 0 || fd >= FD_HARD_LIMIT)
		return ;
	if (g_stash[fd])
	{
		free(g_stash[fd]);
		g_stash[fd] = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;

	if ((fd < 0 || fd > FD_HARD_LIMIT) || BUFFER_SIZE <= 0
		|| read(fd, 0, 0) < 0)
	{
		free(g_stash[fd]);
		g_stash[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, g_stash[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	g_stash[fd] = extract_line(line);
	return (line);
}
