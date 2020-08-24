/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:54:27 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/26 22:03:32 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		minus;

	minus = 1;
	i = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		minus = -1;
	n *= minus;
	if (!(str = malloc(sizeof(char ) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (minus == -1)
		str[0] = '-';
	return (str);
}
