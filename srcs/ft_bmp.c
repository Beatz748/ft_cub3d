/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:27:56 by kshantel          #+#    #+#             */
/*   Updated: 2020/11/17 19:10:32 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*dst;//erfergferggver

	dst = data->addr + (y * data->lln + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}

int				write_bmp_data(int file, t_data *w, t_info *p)
{
	int					i;
	int					j;
	int					color;

	i = (int)p->sch - 1;
	while (i > 0)
	{
		j = 0;
		while (j < (int)p->scw)
		{
			color = get_color(w, j, i);
			if (write(file, &color, 4) < 0)
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int				bitmap_info_header(t_data *mlx_img, int fd, t_info *p)
{
	int	header_info_size;
	int	plane_nbr;
	int	o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &p->scw, 4);
	write(fd, &p->sch, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &mlx_img->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (1);
}

int				ft_create_bitmap(t_data *mlx_img, t_info *p)
{
	int	fd;
	int	file_size;
	int	first_pix;

	if ((fd = open("screenshot.bmp", O_CREAT
	| O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
		ft_error(9);
	file_size = 14 + 40 + 4 + (p->scw * p->sch) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(mlx_img, fd, p);
	write_bmp_data(fd, mlx_img, p);
	close(fd);
	return (1);
}

void			ft_bmp(char *name)
{
	int		fd;
	t_info	p;

	if ((fd = open(name, O_RDONLY)) < 0)
		ft_error(9);
	p.scr = 1;
	ft_start_parsing(fd, &p);
	ft_first_image(&p);
	ft_create_bitmap(&p.img, &p);
}
