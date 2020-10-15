/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <shantel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:41:04 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/15 20:41:04 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init2(t_info *p)
{
	p->num_s = 0;
	p->tex[0].img = NULL;
	p->tex[1].img = NULL;
	p->tex[2].img = NULL;
	p->tex[3].img = NULL;
	p->tex[4].img = NULL;
}

void	ft_initialization(t_info *p)
{
	p->scw = 0;
	p->sch = 0;
	p->f = -1;
	p->c = -1;
	p->mlx = mlx_init();
	p->win = 0;
	p->plx = 0;
	p->ply = 0;
	p->dirx = -1;
	p->diry = 0;
	p->posx = 0;
	p->posy = 0;
	p->camera = 0;
	p->move.a = 0;
	p->move.s = 0;
	p->move.d = 0;
	p->move.w = 0;
	p->move.left = 0;
	p->move.right = 0;
	p->raydirx = 0;
	p->raydiry = 0;
	p->math.d_x = 0;
	p->math.d_y = 0;
	ft_init2(p);
}

void	ft_get_started(char *name)
{
	int		fd;
	size_t	len;
	t_info	p;

	len = ft_strlen(name);
	if (!(name[len - 4] == '.' && name[len - 3] == 'c'\
	&& name[len - 2] == 'u' && name[len - 1] == 'b'))
		ft_error(2);
	if ((fd = open(name, O_RDONLY)) < 0)
		ft_error(9);
	p.scr = 0;
	ft_start_parsing(fd, &p);
	ft_start_drawing(&p);
}

int		main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			ft_get_started(argv[1]);
		if (argc == 3 && (((!(ft_strncmp(argv[2], "––save", 7))))
		|| ((!(ft_strncmp(argv[2], "--save", 7))))))
			ft_bmp(argv[1]);
		else
			ft_error(8);
	}
	else
		ft_error(1);
	return (0);
}
