#include "cub3d.h"

int worldMap[24][24]={
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void  ft_init(t_param *p)
{
	p->dirX = -1;
	p->dirY = 0;
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
			if (worldMap[map->mapX][map->mapY] > 0) 
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
		while(!(ft_check_map(p, map, stepX, stepY)));
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
	wallHit -= floor((wallHit));
		texX = (int)(wallHit * (double)(64));
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
if (keycode == W)
	{
      if(worldMap[(int)(p->posX + p->dirX * 0.25)][(int)(p->posY)] == 0) p->posX += p->dirX * 0.25;
      if(worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * 0.25)] == 0) p->posY += p->dirY * 0.25;
	}
	else if (keycode == S)
	{
      if(worldMap[(int)(p->posX - p->dirX * 0.25)][(int)(p->posY)] == 0)
      p->posX -= p->dirX * 0.25;
      if(worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * 0.25)] == 0)
      p->posY -= p->dirY * 0.25;
	}
else if (keycode == A)
{
if(worldMap[(int)p->posX][(int)(p->posY + p->dirX * moveSpeed)] == 0)
p->posY += p->dirX * moveSpeed;
if(worldMap[(int)(p->posX - p->dirY * moveSpeed)][(int)p->posY] == 0)
p->posX -= p->dirY * moveSpeed;
}
else if (keycode == D)
{
if(worldMap[(int)p->posX][(int)(p->posY - p->dirX * moveSpeed)] == 0)
p->posY -= p->dirX * moveSpeed;
if(worldMap[(int)(p->posX + p->dirY * moveSpeed)][(int)p->posY] == 0)
p->posX += p->dirY * moveSpeed;
}
	else if (keycode == LEFT || keycode == Q)
	{
      double oldDirX = p->dirX;
      p->dirX = p->dirX * cos(rotSpeed) - p->dirY * sin(rotSpeed);
      p->dirY = oldDirX * sin(rotSpeed) + p->dirY * cos(rotSpeed);
      double oldPlaneX = p->planeX;
      p->planeX = p->planeX * cos(rotSpeed) - p->planeY * sin(rotSpeed);
      p->planeY = oldPlaneX * sin(rotSpeed) + p->planeY * cos(rotSpeed);
    }
	else if (keycode == RIGHT || keycode == E)
	{
     double oldDirX = p->dirX;
      p->dirX = p->dirX * cos(-rotSpeed) - p->dirY * sin(-rotSpeed);
      p->dirY = oldDirX * sin(-rotSpeed) + p->dirY * cos(-rotSpeed);
      double oldPlaneX = p->planeX;
      p->planeX = p->planeX * cos(-rotSpeed) - p->planeY * sin(-rotSpeed);
      p->planeY = oldPlaneX * sin(-rotSpeed) + p->planeY * cos(-rotSpeed);
    }
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
	int buf[p->scW];

	x = 0;
	// if (&img != NULL)
	// 	mlx_destroy_image(p->mlx, &img);
    img.img = mlx_new_image(p->mlx, p->scW, p->scH);
  	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(x < p->scW)
	{
		ft_start(p, x, &map);
		ft_part1(p, &map);
		texX = ft_part2(p, &map);
		ft_drawing(p, &map, texX, x, &img);
		buf[x] = map.perpWallDist;
		x++;
	}
	double spriteX = 16 - p->posX;
    double spriteY = 11 - p->posY;
	double invDet = 1.0 / (p->planeX * p->dirY - p->dirX * p->planeY);
	double transformX = invDet * (p->dirY * spriteX - p->dirX * spriteY);
	double transformY = invDet * (-p->planeY * spriteX + p->planeX * spriteY);
	int spriteScreenX = (int)((p->scW / 2) * (1 + transformX / transformY));
      #define uDiv 1
      #define vDiv 1
      #define vMove 0.0
      int vMoveScreen = (int)(vMove / transformY);
	  int spriteHeight = abs((int)(p->scH / (transformY)));
	  int drawStartY = -spriteHeight / 2 + p->scH / 2 + vMoveScreen;
	        if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + p->scH / 2 + vMoveScreen;
      if(drawEndY >= p->scH) drawEndY = p->scH - 1;
	      int spriteWidth = abs( (int) (p->scH / (transformY))) / uDiv;
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= p->scW) drawEndX = p->scW - 1;
	  int stripe = drawStartX;
	  while (stripe < drawEndX)
	  {
		  int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
		  if(transformY > 0 && stripe > 0 && stripe < p->scW && transformY < buf[stripe])
		  {
			  int y = drawStartY;
		  while (y < drawEndY)
		  {
			  int d = (y-vMoveScreen) * 256 - p->scH * 128 + spriteHeight * 128;
			  int texY = ((d * 64) / spriteHeight / 256) ;
			  ft_line2(stripe, p, &img, texX, &p->SP, &map);
			  unsigned int color = get_color(&p->SP, texX,  texY);
			  if (color != 0x000000)
					my_mlx_pixel_put(&img, stripe, y, color);
			  y++;
		  }
		  }
		  stripe++;
		  }
	mlx_put_image_to_window(p->mlx, p->win, img.img, 0, 0);
	return (0);
}

//16;11

int main()
{
	t_param p;
	char *line;
	int fd;
	t_list *mapa;

	ft_init(&p);
	p.posX = 22;
	p.posY = 12;
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
