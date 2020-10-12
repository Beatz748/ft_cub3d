/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 12:33:52 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/12 17:31:50 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_check_cl(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
	|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int		ft_check_set(char const *set, char c)
{
	size_t i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	i_start;
	size_t	i_end;
	char	*str;

	i_start = 0;
	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i_start] != '\0' && ft_check_set(set, s1[i_start]))
		i_start++;
	i_end = ft_strlen(s1);
	while (i_end > i_start && ft_check_set(set, s1[i_end - 1]))
		i_end--;
	if (!(str = (char*)malloc(sizeof(*s1) * (i_end - i_start + 1))))
		return (NULL);
	while (i_start < i_end)
	{
		str[i] = s1[i_start];
		i++;
		i_start++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == c)
			return (dest + i);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
