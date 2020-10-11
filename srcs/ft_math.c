/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:50:50 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init(t_info *p)
{
	p->camera = 2 * p->x / (double)p->scw - 1;
	p->raydirx = p->dirx + p->plx * p->camera;
	p->raydiry = p->diry + p->ply * p->camera;
	p->math.d_x = fabs(1 / p->raydirx);
	p->math.d_y = fabs(1 / p->raydiry);
	p->math.mapx = p->posx;
	p->math.mapy = p->posy;
	p->math.hit = 0;
}

void	ft_steps(t_info *p)
{
	if (p->raydirx < 0)
	{
		p->math.stepx = -1;
		p->math.side_x = (p->posx - p->math.mapx) * p->math.d_x;
	}
	else
	{
		p->math.stepx = 1;
		p->math.side_x = (p->math.mapx + 1.0 - p->posx) * p->math.d_x;
	}
	if (p->raydiry < 0)
	{
		p->math.stepy = -1;
		p->math.side_y = (p->posy - p->math.mapy) * p->math.d_y;
	}
	else
	{
		p->math.stepy = 1;
		p->math.side_y = (p->math.mapy + 1.0 - p->posy) * p->math.d_y;
	}
}

void	ft_meet_wall(t_info *p)
{
	while (p->math.hit == 0)
	{
		if (p->math.side_x < p->math.side_y)
		{
			p->math.side_x += p->math.d_x;
			p->math.mapx += p->math.stepx;
			p->math.side = 0;
		}
		else
		{
			p->math.side_y += p->math.d_y;
			p->math.mapy += p->math.stepy;
			p->math.side = 1;
		}
		if (p->map[p->math.mapy][p->math.mapx] == '1')
			p->math.hit = 1;
	}
}

void	ft_perp_wall(t_info *p)
{
	if (p->math.side == 0)
	{
		p->math.pwd = (p->math.mapx - p->posx + (1 - p->math.stepx) / 2);
		p->math.pwd /= p->raydirx;
	}
	else
	{
		p->math.pwd = (p->math.mapy - p->posy + (1 - p->math.stepy) / 2);
		p->math.pwd /= p->raydiry;
	}
	p->math.lh = (int)(p->sch / p->math.pwd);
	p->math.draws = (-p->math.lh + p->sch) / 2;
	if (p->math.draws < 0)
		p->math.draws = 0;
	p->math.drawe = (p->math.lh + p->sch) / 2;
	if (p->math.drawe >= p->sch)
		p->math.drawe = p->sch - 1;
}

void	ft_wall_hit(t_info *p)
{
	if (p->math.side == 0)
		p->math.wallh = p->posy + p->math.pwd * p->raydiry;
	else
		p->math.wallh = p->posx + p->math.pwd * p->raydirx;
	p->math.wallh -= (int)p->math.wallh;
	if (p->math.side == 0)
	{
		if (p->math.stepx < 0)
			p->math.texx = (int)(p->math.wallh * (double)(p->tex[0].wdt));
		else
			p->math.texx = (int)(p->math.wallh * (double)(p->tex[1].wdt));
	}
	else
	{
		if (p->math.stepy < 0)
			p->math.texx = (int)(p->math.wallh * (double)(p->tex[2].wdt));
		else
			p->math.texx = (int)(p->math.wallh * (double)(p->tex[3].wdt));
	}
}
