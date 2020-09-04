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
	else if (keycode == ESC)
{
		mlx_clear_window(p->mlx, p->win);
}
return (0);
}