/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_par_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:35:22 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_check_res(t_info *p)
{
	int w;
	int	h;

	mlx_get_screen_size(p->mlx, &w, &h);
	if (p->sch > h)
		p->sch = h;
	if (p->scw > w)
		p->scw = w;
}

void	ft_parse_resolution(t_info *p, char *line)
{
	line++;
	while (*line == ' ' || *line == '0')
		line++;
	p->scw = ft_atoi(line);
	line += ft_intlen(p->scw);
	if (*line != ' ')
		ft_error(5);
	while (*line == ' ' || *line == '0')
		line++;
	p->sch = ft_atoi(line);
	line += ft_intlen(p->sch);
	while (*line == ' ')
		line++;
	if (*line != ' ' && *line != '\n' && *line != '\0')
		ft_error(5);
	ft_check_res(p);
}
