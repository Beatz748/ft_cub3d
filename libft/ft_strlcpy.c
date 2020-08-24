/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:53:46 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/29 19:02:41 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t x;

	x = 0;
	if (!dst || !src)
		return (0);
	while (src[x] && x < dstsize - 1 && dstsize)
	{
		dst[x] = src[x];
		x++;
	}
	if (dstsize)
		dst[x] = '\0';
	return (ft_strlen(src));
}
