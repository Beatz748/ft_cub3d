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
	tmp = tmp->next;
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
	map->mapX = 12;
	map->mapY = 5;
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
			if (p->Map[map->mapX][map->mapY] == '1') 
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
		map->lineHeight = (int)(p->scH / map->perpWallDist);
		map->drawS = -map->lineHeight / 2 + p->scH / 2;
		if(map->drawS < 0)
			map->drawS = 0;
		map->drawE = map->lineHeight / 2 + p->scH /2;
		if (map->drawE >= p->scH)
			map->drawE = p->scH - 1;
		
}

unsigned int      get_color(t_data *data, int x, int y)
{

    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		ft_part2(t_param *p, t_map *map)
{
	double wallHit;
	int texX;

	texX = (int)(wallHit * (double)(64));
	if (map->side == 0)
		wallHit = p->posY + map->perpWallDist * p->rayDirY;
	else
		wallHit = p->posX + map->perpWallDist * p->rayDirX;
      if(map->side == 0 && p->rayDirX > 0) 
	  texX = 64 - texX - 1;
      if(map->side == 1 && p->rayDirY < 0) 
	  texX = 64 - texX - 1;
	  return (texX);
}

void			ft_line2(int x, t_param *p, t_data *img, int texX, t_data *wood, t_map *map)
{
  unsigned int color;
  double texPos;
  int texY;
  double step = 1.5 * p->scH / map->lineHeight;
  double drawing;
  drawing = (double)map->drawS;
  texPos = (map->drawS - p->scH / 2 + map->lineHeight / 2) * step;
	while (map->drawS < map->drawE)
	{
		color = get_color(wood, texX, texPos/17);
    if (map->side == 1) color = (color >> 1) & 8355711;
    my_mlx_pixel_put(img, x, map->drawS, color);
    texPos += step ;
		map->drawS++;
	}
}

void	ft_drawing(t_param *p, t_map *map, int texX, int x, t_data *img)
{
	if (p->posY > map->mapY && map->side)
		ft_line2(x, p, img, texX, &p->NO, map);
	else if (p->posY < map->mapY && map->side)
		ft_line2(x, p, img, texX, &p->NO, map);
	else if (p->posX > map->mapX && !map->side)
		ft_line2(x, p, img, texX, &p->NO, map);
	else if (p->posX < map->mapX && !map->side)
		ft_line2(x, p, img, texX, &p->NO, map);    
}

int  ft_change_dir(int keycode, t_param *p)
{
	if (keycode == ESC)
{
		mlx_clear_window(p->mlx, p->win);
		exit(0);
}
return (0);
}
int	ft_image(t_param *p)
{
	int x;
	t_data img;
	int perpWallDist;
	t_map map;
	int texX;

	x = 0;
    img.img = mlx_new_image(p->mlx, p->scW, p->scH);
  	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(x < p->scW)
	{
		ft_start(p, x, &map);
		ft_part1(p, &map);
		texX = ft_part2(p, &map);
		ft_drawing(p, &map, texX, x, &img);
		x++;
	}
	mlx_put_image_to_window(p->mlx, p->win, img.img, 0, 0);
	return (0);
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
	}
	free(line);
	p.Map = making_mapa(&mapa, ft_lstsize(mapa), &p);
	p.win = mlx_new_window(p.mlx, p.scW, p.scH, "cub3d");
    mlx_hook(p.win, X_EVENT_KEY_PRESS, 0, &ft_change_dir, &p);
  	mlx_loop_hook(p.mlx, &ft_image, &p);
    mlx_loop(p.mlx);
	return (0);
}
