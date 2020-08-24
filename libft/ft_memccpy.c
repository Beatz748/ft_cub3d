/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:50:50 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/29 19:50:29 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		if (ds[i] == (unsigned char)c)
			return ((void*)(ds + i + 1));
		i++;
	}
	return (NULL);
}
