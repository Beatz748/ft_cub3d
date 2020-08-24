/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:50:56 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/26 21:51:07 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *ds;
	char *sr;

	if (!src && !dst)
		return (0);
	ds = (char *)dst;
	sr = (char *)src;
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
