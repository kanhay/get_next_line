/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:28:33 by khanhayf          #+#    #+#             */
/*   Updated: 2023/02/12 18:43:36 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_toread(char *str, int fd)
{
	int		nbytes;
	char	*save;

	save = (char *)malloc(BUFFER_SIZE + 1);
	if (!save)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && !(ft_strchr(str, '\n')))
	{
		nbytes = read(fd, save, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (save);
			free (str);
			return (NULL);
		}
		save[nbytes] = '\0';
		if (nbytes == 0)
			break ;
		str = ft_strjoin(str, save);
	}
	free (save);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*s;
	static char		*p;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = p;
	s = ft_toread(s, fd);
	if (!s)
		return (p = NULL, NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	line = ft_substr(s, 0, i + 1);
	if (s[i] == '\0' || (s[i] == '\n' && s[i + 1] == '\0'))
		p = NULL;
	else if (s[i++] == '\n')
		p = ft_substr(s, i, ft_strlen(s) - i);
	free(s);
	return (line);
}
