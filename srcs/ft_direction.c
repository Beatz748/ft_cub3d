/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:20:29 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_turn(t_info *p)
{
	double olddir;
	double oldpl;

	oldpl = p->plx;
	olddir = p->dirx;
	if (p->move.right)
	{
		p->dirx = p->dirx * cos(ROTSPD) - p->diry * sin(ROTSPD);
		p->diry = olddir * sin(ROTSPD) + p->diry * cos(ROTSPD);
		p->plx = p->plx * cos(ROTSPD) - p->ply * sin(ROTSPD);
		p->ply = oldpl * sin(ROTSPD) + p->ply * cos(ROTSPD);
	}
	if (p->move.left)
	{
		p->dirx = p->dirx * cos(-ROTSPD) - p->diry * sin(-ROTSPD);
		p->diry = olddir * sin(-ROTSPD) + p->diry * cos(-ROTSPD);
		p->plx = p->plx * cos(-ROTSPD) - p->ply * sin(-ROTSPD);
		p->ply = oldpl * sin(-ROTSPD) + p->ply * cos(-ROTSPD);
	}
}

void	ft_left_right(t_info *p)
{
	double oldposx;
	double oldposy;

	if (p->move.d)
	{
		oldposx = p->posx - p->diry * MVSPD;
		oldposy = p->posy + p->dirx * MVSPD;
		if (p->map[(int)(p->posy)][(int)(oldposx + 0.01)] == '0' &&
				p->map[(int)(p->posy)][(int)(oldposx - 0.01)] == '0')
			p->posx -= p->diry * MVSPD;
		if (p->map[(int)(oldposy + 0.01)][(int)(p->posx)] == '0' &&
				p->map[(int)(oldposy - 0.01)][(int)(p->posx)] == '0')
			p->posy += p->dirx * MVSPD;
	}
	if (p->move.a)
	{
		oldposx = p->posx + p->diry * MVSPD;
		oldposy = p->posy - p->dirx * MVSPD;
		if (p->map[(int)(p->posy)][(int)(oldposx + 0.01)] == '0' &&
				p->map[(int)(p->posy)][(int)(oldposx - 0.01)] == '0')
			p->posx += p->diry * MVSPD;
		if (p->map[(int)(oldposy + 0.01)][(int)(p->posx)] == '0' &&
				p->map[(int)(oldposy - 0.01)][(int)(p->posx)] == '0')
			p->posy -= p->dirx * MVSPD;
	}
}

void	ft_go(t_info *p)
{
	double oldposx;
	double oldposy;

	if (p->move.w)
	{
		oldposx = p->posx + p->dirx * MVSPD;
		oldposy = p->posy + p->diry * MVSPD;
		if (p->map[(int)(p->posy)][(int)(oldposx + 0.01)] == '0' &&
				p->map[(int)(p->posy)][(int)(oldposx - 0.01)] == '0')
			p->posx += p->dirx * MVSPD;
		if (p->map[(int)(oldposy + 0.01)][(int)(p->posx)] == '0' &&
				p->map[(int)(oldposy - 0.01)][(int)(p->posx)] == '0')
			p->posy += p->diry * MVSPD;
	}
	if (p->move.s)
	{
		oldposx = p->posx - p->dirx * MVSPD;
		oldposy = p->posy - p->diry * MVSPD;
		if (p->map[(int)(p->posy)][(int)(oldposx + 0.01)] == '0' &&
				p->map[(int)(p->posy)][(int)(oldposx - 0.01)] == '0')
			p->posx -= p->dirx * MVSPD;
		if (p->map[(int)(oldposy + 0.01)][(int)(p->posx)] == '0' &&
				p->map[(int)(oldposy - 0.01)][(int)(p->posx)] == '0')
			p->posy -= p->diry * MVSPD;
	}
}

void	ft_move(t_info *p)
{
	if (p->move.a || p->move.d)
		ft_left_right(p);
	if (p->move.w || p->move.s)
		ft_go(p);
	if (p->move.left || p->move.right)
		ft_turn(p);
}
