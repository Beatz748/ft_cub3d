/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:39:53 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/12 22:48:56 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ROTSPD 0.04
# define MVSPD 0.06
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

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct	s_list
{
	void					*content;
	struct s_list			*next;
}				t_list;

typedef struct	s_data {
	void				*img;
	char				*addr;
	int					bpp;
	int					lln;
	int					endian;
}				t_data;

typedef struct	s_tex {
	void				*img;
	int					*addr;
	int					bpp;
	int					lln;
	int					endian;
	int					wdt;
	int					hgt;
}				t_tex;

typedef struct	s_orientation {
	int					w;
	int					s;
	int					a;
	int					d;
	int					left;
	int					right;
}				t_ori;

typedef	struct	s_map_info{
	double			side_x;
	double			side_y;
	int				stepx;
	int				stepy;
	double			step;
	double			pwd;
	int				lh;
	int				mapx;
	int				mapy;
	double			wallh;
	int				side;
	int				texx;
	int				draws;
	double			d_x;
	double			d_y;
	int				drawe;
	int				player;
	int				hit;
}				t_map;

typedef struct	s_sprite{
	double	x;
	double	y;
}				t_sprite;

typedef	struct	s_info{
	int				scw;
	int				sch;
	int				f;
	int				c;
	void			*mlx;
	void			*win;
	t_tex			tex[5];
	double			dirx;
	double			diry;
	double			posx;
	t_ori			move;
	t_sprite		*sprite;
	int				num_s;
	double			posy;
	double			plx;
	double			ply;
	double			camera;
	double			raydirx;
	double			raydiry;
	char			**map;
	t_map			math;
	t_data			img;
	int				y;
	double			texpos;
	int				x;
	int				scr;
}				t_info;

typedef struct	s_sp{
	double			x;
	double			y;
	double			trnx;
	double			trny;
	double			invdet;
	int				screen;
	int				hgt;
	int				startx;
	int				endx;
	int				starty;
	int				endy;
	int				width;
}				t_sp;

int				ft_error2(t_info *p);
int				ft_check_cl(int c);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_save_player(int i, int j, t_info *p, char **map);
void			ft_valid(char **map, t_info *p);
void			ft_tex_sprite(t_info *p, t_sp *s);
void			ft_final_sprite(t_info *p, t_sp *s);
int				ft_intlen(int n);
int				ft_atoi(const char *str);
void			ft_turn(t_info *p);
void			ft_matrix(t_sp *s, t_info *p, int *order, int i);
void			ft_go(t_info *p);
void			ft_check_xpm(char *new);
void			ft_move(t_info *p);
void			ft_go(t_info *p);
void			ft_sprite(t_info *p, double *buf);
int				ft_press(int keycode, t_info *p);
int				ft_unpress(int keycode, t_info *p);
void			*ft_memchr(const void *s, int c, size_t n);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_lstsize(t_list *lst);
void			ft_parse_ceil(t_info *p, char *line);
void			ft_parse_ea(t_info *p, char *line);
void			ft_parse_we(t_info *p, char *line);
void			ft_parse_so(t_info *p, char *line);
void			ft_start_drawing(t_info *p);
void			ft_parse_sp(t_info *p, char *line);
void			ft_parse_no(t_info *p, char *line);
void			ft_left_right(t_info *p);
void			ft_parse_floor(t_info *p, char *line);
void			ft_first_image(t_info *p);
int				ft_checking_all(t_info *p);
int				ft_parser(t_info *p, char *line);
void			ft_change_dir(t_info *p);
int				ft_press(int keycode, t_info *p);
int				ft_unpress(int keycode, t_info *p);
void			ft_parse_ceil(t_info *p, char *line);
void			ft_parse_floor(t_info *p, char *line);
void			ft_parse_resolution(t_info *p, char *line);
char			*ft_strchr(const char *s, int c);
void			ft_check_orientation(t_info *p, char *line);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_check_set(char const *set, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
void			ft_start_parsing(int fd, t_info *p);
void			ft_initialization(t_info *p);
void			ft_draw(t_info *p, t_tex tex);
void			ft_ceil_floor(t_info *p);
void			ft_step_tex(t_info *p);
void			ft_init(t_info *p);
void			ft_steps(t_info *p);
void			ft_meet_wall(t_info *p);
void			ft_perp_wall(t_info *p);
void			ft_wall_hit(t_info *p);
void			ft_get_started(char *name);
void			ft_error(int i);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_sorting(double *dist, int *order, int num);
char			*ft_strdup(const char *s);
char			*check_strdup(const char *s);
void			ft_find_sprite(int i, int j, t_info *p, int *count);
unsigned int	get_color(t_data *data, int x, int y);
int				write_bmp_data(int file, t_data *w, t_info *p);
int				bitmap_info_header(t_data *mlx_img, int fd, t_info *p);
char			**making_map(t_list *mapa, t_info *p);
int				ft_create_bitmap(t_data *mlx_img, t_info *p);
void			ft_bmp(char *name);
int				main(int argc, char **argv);

#endif
