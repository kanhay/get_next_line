/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:29:43 by khanhayf          #+#    #+#             */
/*   Updated: 2022/12/30 14:40:30 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p;
	int		i;

	if (!str)
		return (NULL);
	p = (char *)str;
	i = 0;
	while (p[i])
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i++;
	}
	if (p[i] == (char)c)
		return (&p[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		l1;
	int		l2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!p)
		return (0);
	ft_memcpy(p, s1, l1);
	ft_memcpy(p + l1, s2, l2 + 1);
	free(s1);
	return (p);
}

char	*ft_substr(char *s, unsigned int first, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (*s && i < len && first <= l)
		sub[i++] = s[first++];
	sub[i] = '\0';
	return (sub);
}
