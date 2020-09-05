#include "cub3d.h"

void  ft_init(t_param *p)
{
	p->posX = -1;
	p->posY = 0;
	p->mlx = mlx_init();
	p->win = 0;
	p->F = -1;
	p->C = -1;
	p->scW = -1;
	p->scH = -1;
  	p->planeX = 0;
  	p->planeY = 0.66;
}

void	ft_check_orientation(t_param *p, char *line)
{
	if ((ft_strchr(line, 'S')))
	{
		p->dirX = 1;
		p->planeY = -0.66;
	}
	if ((ft_strchr(line, 'E')))
	{
		p->dirX = 0;
		p->dirY = 1;
		p->planeX = 0.66;
		p->planeY = 0;
	}
	if ((ft_strchr(line, 'W')))
	{
		p->dirX = 0;
		p->dirY = -1;
		p->planeX = -0.66;
		p->planeY = 0;
	}
}

char   **making_mapa(t_list **mapa, int size, t_param *p)
{
    char **map = calloc(size + 1, sizeof(char *));
    int i;
    i = -1;
    t_list *tmp = *mapa;
    while(tmp)
    {
		ft_check_orientation(p, tmp->content);
        map[++i] = tmp->content;
        tmp = tmp->next;
    }
	return (map);
}

void	ft_start(t_param *p, int x, t_map *map)
{
	p->camera = 2 * x / (double)p->scW - 1 ;
	p->rayDirX = p->dirX + p->planeX * p->camera;
	p->rayDirY = p->dirY + p->planeY * p->camera;
	p->deltaDistX = fabs(1 / p->rayDirX);
	p->deltaDistY = fabs(1 / p->rayDirY);
	map->mapX = p->posX;
	map->mapY = p->posY;
}

int	ft_check_map(t_param *p, t_map *map, int stepX, int stepY)
{
	int side;

				if (map->sideDistX < map->sideDistY)
			{
				map->sideDistX += p->deltaDistX;
				map->mapX += stepX;
				map->side = 0;
			}
			else
			{
				map->sideDistY += p->deltaDistY;
				map->mapY += stepY;
				map->side = 1;
			}
			if (p->Map[map->mapX][map->mapY] > 0) 
				return(1);
	return (0);
}

void	ft_part1(t_param *p, t_map *map)
{
	int stepX;
	int stepY;
		if (p->rayDirX < 0)
		{
			stepX = -1;
			map->sideDistX = (p->posX - map->mapX) * p->deltaDistX;
		}
		else
		{
			stepX = 1;
			map->sideDistX = (map->mapX + 1.0 - p->posX) * p->deltaDistX;
		}
		if (p->rayDirY < 0)
		{
			stepY = -1;
			map->sideDistY = (p->posY - map->mapY) * p->deltaDistY;
		}
		else
		{
			stepY = 1;
			map->sideDistY = (map->mapY + 1.0 - p->posY) * p->deltaDistY;
		}
		while((ft_check_map(p, map, stepX, stepY)));
		if (map->side == 0) 
			map->perpWallDist = (map->mapX - p->posX + (1 - stepX) / 2) / p->rayDirX;
		else          
			map->perpWallDist = (map->mapY - p->posY + (1 - stepY) / 2) / p->rayDirY;
}

void	ft_image(t_param *p)
{
	int x;
	t_data img;
	int perpWallDist;
	t_map map;

	x = 0;
    img.img = mlx_new_image(p->mlx, p->scW, p->scH);
  	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(x < p->scW)
	{
		ft_start(p, x, &map);
		ft_part1(p, &map);
		x++;
	}
}
int main()
{
	t_param p;
	char *line;
	int fd;
	t_list *mapa;

	ft_init(&p);
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!(ft_checking_all(&p)))
		{
			ft_parser(&p, line);
			free(line);
		}
		else
			ft_lstadd_back(&mapa, ft_lstnew(line));
	}
	free(line);
	p.Map = making_mapa(&mapa, ft_lstsize(mapa), &p);
	p.win = mlx_new_window(p.mlx, p.scW, p.scH, "cub3d");
    mlx_hook(p.win, X_EVENT_KEY_PRESS, 0, &ft_change_dir, &p);
  	mlx_loop_hook(p.mlx, &ft_image, &p);
    mlx_loop(p.mlx);
	return (0);
}
