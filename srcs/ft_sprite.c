/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:23:48 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_matrix(t_sp *s, t_info *p, int *order, int i)
{
	s->x = p->sprite[order[i]].x - p->posx;
	s->y = p->sprite[order[i]].y - p->posy;
	s->invdet = 1.0 / (p->plx * p->diry - p->dirx * p->ply);
	s->trnx = s->invdet * (p->diry * s->x - p->dirx * s->y);
	s->trny = s->invdet * (-p->ply * s->x + p->plx * s->y);
	s->screen = (int)((p->scw / 2) * (1 + s->trnx / s->trny));
	s->hgt = abs((int)(p->sch / s->trny));
}

void	ft_tex_sprite(t_info *p, t_sp *s)
{
	s->starty = -s->hgt / 2 + p->sch / 2;
	if (s->starty < 0)
		s->starty = 0;
	s->endy = s->hgt / 2 + p->sch / 2;
	if (s->endy >= p->sch)
		s->endy = p->sch - 1;
	s->width = abs((int)(p->sch / s->trny));
	s->startx = -s->width / 2 + s->screen;
	if (s->startx < 0)
		s->startx = 0;
	s->endx = s->width / 2 + s->screen;
	if (s->endx >= p->scw)
		s->endx = p->scw - 1;
}

void	ft_final_sprite(t_info *p, t_sp *s)
{
	int x;
	int texy;
	int color;

	while (p->y < s->endy)
	{
		x = p->y * 256 - p->sch * 128 + s->hgt * 128;
		texy = ((x * p->tex[4].hgt) / s->hgt) / 256;
		color = p->tex[4].addr[p->tex[4].wdt * texy + p->math.texx];
		if (color != -0x1000000)
			my_mlx_pixel_put(&p->img, p->x, p->y, color);
		p->y++;
	}
}

void	ft_draw_sprite(t_info *p, t_sp *s, double *buf)
{
	p->x = s->startx;
	while (p->x < s->endx)
	{
		p->y = s->starty;
		p->math.texx = (int)256 * (p->x - (-s->width / 2 + s->screen));
		p->math.texx = p->math.texx * p->tex[4].wdt / s->width / 256;
		if (s->trny > 0 && p->x > 0 && p->x < p->scw
				&& s->trny < buf[p->x])
			ft_final_sprite(p, s);
		p->x++;
	}
}

void	ft_sprite(t_info *p, double *buf)
{
	t_sp	s;
	int		i;
	double	dist[p->num_s];
	int		order[p->num_s];

	i = 0;
	while (i < p->num_s)
	{
		order[i] = i;
		dist[i] = pow((p->posx - p->sprite[i].x), 2);
		dist[i] += pow((p->posy - p->sprite[i].y), 2);
		i++;
	}
	i = 0;
	ft_sorting(dist, order, p->num_s);
	while (i < p->num_s)
	{
		ft_matrix(&s, p, order, i);
		ft_tex_sprite(p, &s);
		ft_draw_sprite(p, &s, buf);
		i++;
	}
}
