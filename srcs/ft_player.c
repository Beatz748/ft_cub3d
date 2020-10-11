/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:38:12 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_ori_se(t_info *p, char *line)
{
	if ((ft_strchr(line, 'S')))
	{
		p->dirx = 0;
		p->diry = 1;
		p->plx = -1;
		p->ply = 0;
	}
	if ((ft_strchr(line, 'E')))
	{
		p->dirx = 1;
		p->diry = 0;
		p->plx = 0;
		p->ply = 1;
	}
}

void	ft_check_orientation(t_info *p, char *line)
{
	if ((ft_strchr(line, 'S')) || (ft_strchr(line, 'E')))
		ft_ori_se(p, line);
	if ((ft_strchr(line, 'N')))
	{
		p->dirx = 0;
		p->diry = -1;
		p->plx = 1;
		p->ply = 0;
	}
	if ((ft_strchr(line, 'W')))
	{
		p->dirx = -1;
		p->diry = 0;
		p->plx = 0;
		p->ply = -1;
	}
	while ((ft_strchr(line, '2')))
	{
		line = ft_strchr(line, '2') + 1;
		p->num_s++;
	}
}

void	ft_save_player(int i, int j, t_info *p, char **map)
{
	if (p->posx != 0 || p->posy != 0)
		ft_error(6);
	p->posx = j + 0.5;
	p->posy = i + 0.5;
	map[i][j] = '0';
}

void	ft_find_sprite(int i, int j, t_info *p, int *count)
{
	p->sprite[*count].x = j + 0.5;
	p->sprite[*count].y = i + 0.5;
	*count = *count + 1;
}

void	ft_valid(char **map, t_info *p)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'\
			|| map[i][j] == 'E' || map[i][j] == 'W')
				ft_save_player(i, j, p, map);
			if (map[i][j] == '2')
				ft_find_sprite(i, j, p, &count);
			j++;
		}
		i++;
	}
	if (p->posx == 0 && p->posy == 0)
		ft_error(6);
}
