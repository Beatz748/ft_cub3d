/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:46:34 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str2 = (char *)s;
	while (str2[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(*str2) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = str2[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*check_strdup(const char *s)
{
	char	*new_str;

	if (!(new_str = ft_strdup(s)))
		ft_error(7);
	return (new_str);
}

void	ft_sorting(double *dist, int *order, int num)
{
	double	tmp;
	int		i;
	int		check;

	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		while (i < num - 1)
		{
			if (dist[i] < dist[i + 1])
			{
				tmp = dist[i];
				dist[i] = dist[i + 1];
				dist[i + 1] = tmp;
				tmp = order[i];
				order[i] = order[i + 1];
				order[i + 1] = tmp;
				check = 1;
			}
			i++;
		}
	}
}
