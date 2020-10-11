/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:32:54 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char	buf[2];
	int		sr;
	char	*tmp;

	sr = 0;
	buf[1] = '\0';
	if (!line)
		return (-1);
	if (!(*line = malloc(1)))
		return (-1);
	**line = 0;
	while ((sr = read(fd, buf, 1)))
	{
		if (*buf != '\n')
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
		}
		else
			break ;
	}
	return (sr);
}

int		ft_atoi(const char *str)
{
	size_t				i;
	int					minus;
	unsigned long long	number;

	number = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number < 9223372036854775807)
			number = number * 10 + str[i++] - 48;
		if (number > 9223372036854775807 && minus < 0)
			return (0);
		else if (number > 9223372036854775807)
			return (-1);
	}
	return ((int)(number * minus));
}
