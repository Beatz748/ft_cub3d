/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:17:17 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_parse_ea(t_info *p, char *line)
{
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	ft_check_xpm(new);
	if (!(p->tex[0].img = mlx_xpm_file_to_image(p->mlx, new,
	&p->tex[0].wdt, &p->tex[0].hgt)))
	{
		free(new);
		ft_error(3);
	}
	p->tex[0].addr = (int*)mlx_get_data_addr(p->tex[0].img, &p->tex[0].bpp,
	&p->tex[0].lln, &p->tex[0].endian);
	free(new);
}

void	ft_parse_we(t_info *p, char *line)
{
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	ft_check_xpm(new);
	if (!(p->tex[1].img = mlx_xpm_file_to_image(p->mlx, new,
	&p->tex[1].wdt, &p->tex[1].hgt)))
	{
		free(new);
		ft_error(3);
	}
	p->tex[1].addr = (int*)mlx_get_data_addr(p->tex[1].img, &p->tex[1].bpp,
	&p->tex[1].lln, &p->tex[1].endian);
	free(new);
}

void	ft_parse_so(t_info *p, char *line)
{
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	ft_check_xpm(new);
	if (!(p->tex[2].img = mlx_xpm_file_to_image(p->mlx, new,
	&p->tex[2].wdt, &p->tex[2].hgt)))
	{
		free(new);
		ft_error(3);
	}
	p->tex[2].addr = (int*)mlx_get_data_addr(p->tex[2].img, &p->tex[2].bpp,
	&p->tex[2].lln, &p->tex[2].endian);
	free(new);
}

void	ft_parse_sp(t_info *p, char *line)
{
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	ft_check_xpm(new);
	if (!(p->tex[4].img = mlx_xpm_file_to_image(p->mlx, new,
	&p->tex[4].wdt, &p->tex[4].hgt)))
	{
		free(new);
		ft_error(3);
	}
	p->tex[4].addr = (int*)mlx_get_data_addr(p->tex[4].img,
	&p->tex[4].bpp, &p->tex[4].lln, &p->tex[4].endian);
	free(new);
}

void	ft_parse_no(t_info *p, char *line)
{
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	ft_check_xpm(new);
	if (!(p->tex[3].img = mlx_xpm_file_to_image(p->mlx, new,
	&p->tex[3].wdt, &p->tex[3].hgt)))
	{
		free(new);
		ft_error(3);
	}
	p->tex[3].addr = (int*)mlx_get_data_addr(p->tex[3].img,
	&p->tex[3].bpp, &p->tex[3].lln, &p->tex[3].endian);
	free(new);
}
