/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:58:55 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/26 21:58:57 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
