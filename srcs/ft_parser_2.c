/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:15:52 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_check_xpm(char *new)
{
	int len;

	len = ft_strlen(new);
	if (!(new[len - 4] == '.' && new[len - 3] == 'x'\
	&& new[len - 2] == 'p' && new[len - 1] == 'm'))
		ft_error(4);
}

void	ft_parse_ceil(t_info *p, char *line)
{
	int r;
	int g;
	int b;

	line++;
	while (*line == ' ' || *line == ',')
		line++;
	r = ft_atoi(line);
	line += ft_intlen(r);
	if (*line != ' ' && *line != ',')
		ft_error(10);
	while (*line == ' ' || *line == ',')
		line++;
	g = ft_atoi(line);
	line += ft_intlen(g);
	if (*line != ' ' && *line != ',')
		ft_error(10);
	while (*line == ' ' || *line == ',')
		line++;
	b = ft_atoi(line);
	line += ft_intlen(b);
	if (*line != '\0')
		ft_error(10);
	p->c = mlx_get_color_value(p->mlx, r * 65536 + g * 256 + b);
}

void	ft_parse_floor(t_info *p, char *line)
{
	int r;
	int g;
	int b;

	line++;
	while (*line == ' ' || *line == ',')
		line++;
	r = ft_atoi(line);
	line += ft_intlen(r);
	if (*line != ' ' && *line != ',')
		ft_error(10);
	while (*line == ' ' || *line == ',')
		line++;
	g = ft_atoi(line);
	line += ft_intlen(g);
	if (*line != ' ' && *line != ',')
		ft_error(10);
	while (*line == ' ' || *line == ',')
		line++;
	b = ft_atoi(line);
	line += ft_intlen(b);
	if (*line != '\0')
		ft_error(10);
	p->f = mlx_get_color_value(p->mlx, r * 65536 + g * 256 + b);
}
