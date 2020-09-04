#include "cub3d.h"

void  ft_parse_EA(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	p->EA.img = mlx_xpm_file_to_image(p->mlx, new, &img_width, &img_height);
	p->EA.addr = mlx_get_data_addr(p->EA.img, &p->EA.bits_per_pixel, &p->EA.line_length, &p->EA.endian);
	free(new);
}

void  ft_parse_WE(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	p->WE.img = mlx_xpm_file_to_image(p->mlx, new, &img_width, &img_height);
	p->WE.addr = mlx_get_data_addr(p->WE.img, &p->WE.bits_per_pixel, &p->WE.line_length, &p->WE.endian);
	free(new);
}

void  ft_parse_SO(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	p->SO.img = mlx_xpm_file_to_image(p->mlx, new, &img_width, &img_height);
	p->SO.addr = mlx_get_data_addr(p->SO.img, &p->SO.bits_per_pixel, &p->SO.line_length, &p->SO.endian);
	free(new);
}

void  ft_parse_SP(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	p->SP.img = mlx_xpm_file_to_image(p->mlx, new, &img_width, &img_height);
	p->SP.addr = mlx_get_data_addr(p->SP.img, &p->SP.bits_per_pixel, &p->SP.line_length, &p->SP.endian);
	free(new);
}

void  ft_parse_NO(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;
	char	*new;

	line += 2;
	while (*line == ' ')
		line++;
	new = ft_strtrim(line, " ");
	p->NO.img = mlx_xpm_file_to_image(p->mlx, new, &img_width, &img_height);
	p->NO.addr = mlx_get_data_addr(p->NO.img, &p->NO.bits_per_pixel, &p->NO.line_length, &p->NO.endian);
	free(new);
}