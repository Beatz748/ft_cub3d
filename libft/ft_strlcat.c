/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:53:41 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/29 19:50:01 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = i;
	while (i + 1 < dstsize && src[i - j])
	{
		dst[i] = src[i - j];
		i++;
	}
	if (dstsize > j)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
