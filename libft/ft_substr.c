/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:54:39 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/29 19:39:06 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	x;

	x = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (x < len)
	{
		new[x] = s[start + x];
		x++;
	}
	new[len] = '\0';
	return (new);
}
