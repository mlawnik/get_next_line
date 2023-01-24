/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlawnik <mlawnik@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:48:56 by mlawnik           #+#    #+#             */
/*   Updated: 2023/01/22 14:19:07 by mlawnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (ptr == NULL)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (storage[len] == 0)
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (new_storage == 0)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (line == 0)
		return (NULL);
	return (line);
}

char	*read_file(int fd, char *storage)
{
	int		rid;
	char	*buffer;
	size_t	buffer_size;

	buffer_size = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (buffer_size + 1));
	if (buffer == 0)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while ((rid = read(fd, buffer, buffer_size)) > 0)
	{
		buffer[rid] = '\0';
		if (ft_strchr(buffer, '\n') != 0)
			break ;
		buffer_size *= 2;
		buffer = realloc(buffer, sizeof(char) * (buffer_size + 1));
	}
	if (rid == -1)
		return (ft_free(&storage));
	storage = realloc(storage, ft_strlen(storage) + ft_strlen(buffer) + 1);
	ft_strcat(storage, buffer);
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage != 0 && ft_strchr(storage, '\n') == 0) || storage == 0)
		storage = read_file(fd, storage);
	if (storage == 0)
		return (NULL);
	line = new_line(storage);
	if (line == 0)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (line);
}
