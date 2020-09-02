#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx/mlx.h"

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE	3
# define rotSpeed 0.05
# define moveSpeed 0.25
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define Q 12
# define E 14
# define screenWidth 1280
# define screenHeight 720

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef	struct	s_param{
	void	*mlx;
	void	*win;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	camera;
	double	rayDirX;
	double	sideDistX;
	double	sideDistY;
	double	rayDirY;
	double	dirX;
	double	dirY;
	double	deltaDistX;
	double	deltaDistY;
    int     height;
    int     width;
	char	textureNO;
	char	textureSO;
	char	textureWE;
	char	textureEA;
	char	textureS;
  	double	perpWallDist;
  	int		stepX;
  	int		stepY;
}				t_param;

#endif