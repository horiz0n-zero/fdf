/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:00:30 by afeuerst          #+#    #+#             */
/*   Updated: 2017/05/30 15:13:01 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	ptr = new;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (new);
}

char		*get_content_file(const char *const path)
{
	int		fd;
	char	buffer[2049];
	int		ret;
	char	*result;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = "";
	while ((ret = read(fd, buffer, 2048)))
	{
		buffer[ret] = 0;
		result = ft_strjoin(result, buffer);
	}
	return (result);
}
