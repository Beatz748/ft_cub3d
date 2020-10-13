/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:15:52 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/13 20:39:40 by kshantel         ###   ########.fr       */
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

void	ft_check_less_255(int *c, int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_error(8);
	*c = r * 65536 + g * 256 + b;
}

void	ft_parse_ceil(t_info *p, char *line)
{
	int r;
	int g;
	int b;

	if (p->c != -1)
		ft_error(8);
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
	ft_check_less_255(&p->c, r, g, b);
}

void	ft_parse_floor(t_info *p, char *line)
{
	int r;
	int g;
	int b;

	if (p->f != -1)
		ft_error(8);
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
	ft_check_less_255(&p->f, r, g, b);
}
