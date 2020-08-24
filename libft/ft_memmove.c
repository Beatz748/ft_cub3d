/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:51:19 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/26 21:51:20 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ds;
	unsigned char *sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (!src && !dst)
		return (0);
	if (ds <= sr || ds >= (sr + len))
	{
		while (len--)
			*ds++ = *sr++;
	}
	else
	{
		ds += len - 1;
		sr += len - 1;
		while (len--)
			*ds-- = *sr--;
	}
	return (dst);
}
