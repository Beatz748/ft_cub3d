/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:54:38 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->lln + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw(t_info *p, t_tex tex)
{
	unsigned int	color;
	int				y;

	y = (int)p->texpos & (tex.hgt - 1);
	color = tex.addr[tex.hgt * y + p->math.texx];
	my_mlx_pixel_put(&p->img, p->x, p->y, color);
}

void	ft_ceil_floor(t_info *p)
{
	int y;

	y = 0;
	while (y < p->math.draws)
	{
		my_mlx_pixel_put(&p->img, p->x, y, p->c);
		y++;
	}
	y = p->math.drawe;
	while (y < p->sch)
	{
		my_mlx_pixel_put(&p->img, p->x, y, p->f);
		y++;
	}
}

void	ft_step_tex(t_info *p)
{
	if (p->math.side == 0)
	{
		if (p->math.stepx < 0)
		{
			p->math.step = 1.0 * p->tex[0].hgt / p->math.lh;
			p->math.texx = p->tex[0].hgt - p->math.texx - 1;
		}
		else
			p->math.step = 1.0 * p->tex[1].hgt / p->math.lh;
	}
	else
	{
		if (p->math.stepy < 0)
			p->math.step = 1.0 * p->tex[2].hgt / p->math.lh;
		else
		{
			p->math.step = 1.0 * p->tex[3].hgt / p->math.lh;
			p->math.texx = p->tex[3].hgt - p->math.texx - 1;
		}
	}
}
