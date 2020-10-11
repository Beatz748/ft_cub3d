/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:32:50 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_vald(char **map, int i, int j)
{
	if (!(ft_strchr("NSWE 012", map[i][j])))
		ft_error(7);
	if (map[i][j] == '0')
	{
		if (map[i + 1][j] == ' ' || map[i][j + 1] == ' ' ||
		map[i - 1][j] == ' ' || map[i][j - 1] == ' ')
			ft_error(7);
		if (((int)ft_strlen(map[i - 1]) + 1 < j) ||
		((int)ft_strlen(map[i + 1]) + 1 < j))
			ft_error(7);
	}
}

void	ft_second(char **map, int res)
{
	int	i;
	int	j;

	i = 0;
	while (i < res - 1)
	{
		j = 1;
		if (!(ft_strchr("1 ", map[i][0])))
			ft_error(7);
		while (map[i][j + 1])
			ft_vald(map, i, j++);
		if (!(ft_strchr("1 ", map[i][j])))
			ft_error(7);
		i++;
	}
	j = 0;
	while ((map[res - 1]) && map[res - 1][j])
	{
		if (!(ft_strchr("1 ", map[res - 1][j])))
			ft_error(7);
		j++;
	}
}

void	ft_check(char **map)
{
	int i;
	int	j;
	int res;

	j = 0;
	i = 0;
	res = 0;
	while (map[res])
		res++;
	while ((map[i]) && map[i][j])
	{
		if (!(ft_strchr("1 ", map[i][j])))
			ft_error(7);
		j++;
	}
	ft_second(map, res);
}

char	**making_map(t_list *mapa, t_info *p)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = mapa;
	while (tmp && (*((char *)(tmp->content)) == '\0'))
		tmp = tmp->next;
	map = calloc(ft_lstsize(tmp) + 1, sizeof(char *));
	while (tmp)
	{
		ft_check_orientation(p, tmp->content);
		if (*((char *)(tmp->content)) != '\0')
			map[++i] = check_strdup((char *)tmp->content);
		else
			map[++i] = "11";
		tmp = tmp->next;
	}
	p->sprite = (t_sprite*)malloc(sizeof(t_sprite) * (p->num_s + 1));
	ft_valid(map, p);
	ft_check(map);
	return (map);
}
