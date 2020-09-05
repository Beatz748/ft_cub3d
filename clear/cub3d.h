#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx/mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE	3
# define rotSpeed 0.15
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

typedef struct		s_list
{
    void			*content;
    struct s_list	*next;
}					t_list;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef	struct	s_param{
	int		scW;
	int		scH;
	unsigned int F;
	unsigned int C;
	void	*mlx;
	void	*win;
	t_data	NO;
	t_data	SO;
	t_data	WE;
	t_data	EA;
	t_data	SP;
	double	dirX;
	double	dirY;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	camera;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	char	**Map;
}				t_param;

typedef	struct	s_map{
	double	sideDistX;
	double	sideDistY;
  	double	perpWallDist;
	int		lineHeight;
	int		mapX;
	int		mapY;
	int		side;
	int		drawS;
	int		drawE;

}				t_map;

void  ft_parse_ceil(t_param *p, char *line);

void  ft_parse_EA(t_param *p, char *line);

void  ft_parse_WE(t_param *p, char *line);

void  ft_parse_SO(t_param *p, char *line);

void  ft_parse_SP(t_param *p, char *line);

void  ft_parse_NO(t_param *p, char *line);

void  ft_init(t_param *p);

char	*ft_strchr(const char *s, int c);

int  ft_change_dir(int keycode, t_param *p);

void	ft_clean(t_param *p);

char   **making_mapa(t_list **mapa, int size, t_param *p);

void  ft_parse_floor(t_param *p, char *line);

void  ft_parse_resolution(t_param *p, char *line);

int	ft_checking_all(t_param *p);

int ft_parser(t_param *p, char *line);

void  ft_parse_ceil(t_param *p, char *line);

void  ft_parse_floor(t_param *p, char *line);

void  ft_parse_resolution(t_param *p, char *line);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

int get_next_line(int fd, char **line);

int		ft_intlen(int n);

int	ft_atoi(const char *str);

void		ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstlast(t_list *lst);

t_list		*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);

char	*ft_strtrim(char const *s1, char const *set);

int		ft_check_set(char const *set, char c);

#endif