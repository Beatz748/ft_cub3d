/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:36:08 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_close(t_info *p)
{
	mlx_clear_window(p->mlx, p->win);
	exit(0);
}

int		ft_press(int keycode, t_info *p)
{
	if (keycode == W)
		p->move.w = 1;
	if (keycode == S)
		p->move.s = 1;
	if (keycode == D)
		p->move.d = 1;
	if (keycode == A)
		p->move.a = 1;
	if (keycode == LEFT || keycode == Q)
		p->move.left = 1;
	if (keycode == RIGHT || keycode == E)
		p->move.right = 1;
	if (keycode == ESC)
		ft_close(p);
	return (0);
}

int		ft_unpress(int keycode, t_info *p)
{
	if (keycode == W)
		p->move.w = 0;
	if (keycode == S)
		p->move.s = 0;
	if (keycode == D)
		p->move.d = 0;
	if (keycode == A)
		p->move.a = 0;
	if (keycode == LEFT || keycode == Q)
		p->move.left = 0;
	if (keycode == RIGHT || keycode == E)
		p->move.right = 0;
	return (0);
}
