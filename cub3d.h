#ifndef CUB3D_H
#define CUB3D_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
#define PI 3.1415926535
#define KEY_ESC			53

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct s_param{
	float		x;
	float		y;
	float	    dir;
	void	    *mlx;
	void	    *win;
    int         height;
    int         width;
}				t_param;
void    making_mapa(t_list **mapa, int size, t_param *p);

void			param_init(t_param *p);

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);

void ft_draw(char **map, t_param *p);

#endif
