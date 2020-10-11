/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:23:59 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_draw_walls(t_info *p)
{
	p->y = p->math.draws;
	p->texpos = (p->math.draws - (p->sch + p->math.lh) / 2);
	p->texpos *= p->math.step;
	while (p->y < p->math.drawe)
	{
		p->texpos += p->math.step;
		if (p->math.side == 0)
		{
			if (p->math.stepx < 0)
				ft_draw(p, p->tex[0]);
			else
				ft_draw(p, p->tex[1]);
		}
		else
		{
			if (p->math.stepy < 0)
				ft_draw(p, p->tex[2]);
			else
				ft_draw(p, p->tex[3]);
		}
		p->y++;
	}
}

void	ft_raycast(t_info *p)
{
	double	*buf;

	p->x = 0;
	buf = (double*)malloc(sizeof(double) * p->scw);
	while (p->x < p->scw)
	{
		ft_init(p);
		ft_steps(p);
		ft_meet_wall(p);
		ft_perp_wall(p);
		ft_wall_hit(p);
		ft_step_tex(p);
		ft_draw_walls(p);
		ft_ceil_floor(p);
		buf[p->x] = p->math.pwd;
		p->x++;
	}
	ft_sprite(p, buf);
	free(buf);
}

int		ft_image(t_info *p)
{
	if (!(p->move.a || p->move.s || p->move.d ||
				p->move.w || p->move.left || p->move.right))
		return (0);
	ft_move(p);
	p->img.img = mlx_new_image(p->mlx, p->scw, p->sch);
	p->img.addr = mlx_get_data_addr(p->img.img, &p->img.bpp,
		&p->img.lln, &p->img.endian);
	ft_raycast(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	mlx_destroy_image(p->mlx, p->img.img);
	return (0);
}

void	ft_first_image(t_info *p)
{
	p->win = mlx_new_window(p->mlx, p->scw, p->sch, "cub3d");
	p->img.img = mlx_new_image(p->mlx, p->scw, p->sch);
	p->img.addr = mlx_get_data_addr(p->img.img,
		&p->img.bpp, &p->img.lln, &p->img.endian);
	ft_raycast(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

void	ft_start_drawing(t_info *p)
{
	ft_first_image(p);
	mlx_loop_hook(p->mlx, ft_image, p);
	mlx_hook(p->win, 2, (1L << 0), ft_press, p);
	mlx_hook(p->win, 3, (1L << 1), ft_unpress, p);
	mlx_loop(p->mlx);
}
