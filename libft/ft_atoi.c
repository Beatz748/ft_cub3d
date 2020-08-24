/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 14:39:44 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/29 19:48:40 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
