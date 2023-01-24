/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlawnik <mlawnik@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:53:31 by mlawnik           #+#    #+#             */
/*   Updated: 2023/01/22 14:03:58 by mlawnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (s1 == 0)
	{
		s1 = malloc(sizeof(char) + 1);
		if (s1 == 0)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == 0)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i] != 0)
		str[i] = s1[i];
	c = -1;
	while (s2[++c] != 0)
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != (unsigned char)c)
		if (*s++ == 0)
			return (0);
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*substring;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + len >= s_len)
		len = s_len - start;
	if (len > s_len)
		substring = malloc(s_len + 1);
	else
		substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	if (start <= s_len)
	{
		ft_strlcpy((char *) substring, &s[start], len + 1);
		return ((char *) substring);
	}
	((char *) substring)[0] = '\0';
	return ((char *) substring);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != 0)
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}
