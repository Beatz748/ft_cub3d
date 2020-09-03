#include "cub3d.h"

void  ft_init(t_param *p)
{
	p->posX = 0;
	p->posY = 0;
	p->planeX = 0;
	p->planeX = 0;
	p->mlx = mlx_init();
	p->win = 0;
	p->F = -1;
	p->C = -1;
	p->scW = -1;
	p->scH = -1;
}

void  ft_parse_ceil(t_param *p, char *line)
{
	int R;
	int G;
	int B;

	line++;
	while (*line == ' ' || *line == ',')
		line++;
	R = ft_atoi(line);
	line += ft_intlen(R);
	while (*line == ' ' || *line == ',')
		line++;    
	G = ft_atoi(line);
	line += ft_intlen(G);
	while (*line == ' ' || *line == ',')
		line++;
	B = ft_atoi(line);
	p->C = mlx_get_color_value(p->mlx, R*65536+G*256+B);
}

void  ft_parse_floor(t_param *p, char *line)
{
	int R;
	int G;
	int B;

	line++;
	while (*line == ' ' || *line == ',')
		line++;
	R = ft_atoi(line);
	line += ft_intlen(R);
	while (*line == ' ' || *line == ',')
		line++;    
	G = ft_atoi(line);
	line += ft_intlen(G);
	while (*line == ' ' || *line == ',')
		line++;
	B = ft_atoi(line);
	p->F = mlx_get_color_value(p->mlx, R*65536+G*256+B);
}

void  ft_parse_resolution(t_param *p, char *line)
{
	line++;
	while (*line == ' ')
		line++;
	p->scW = ft_atoi(line);
	line += ft_intlen(p->scW);
	while (*line == ' ')
		line++;
	p->scH = ft_atoi(line);
}

void  ft_parse_EA(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;

	line += 2;
	while (*line == ' ')
		line++;
	p->EA.img = mlx_xpm_file_to_image(p->mlx, ft_strtrim(line, " "), &img_width, &img_height);
	p->EA.addr = mlx_get_data_addr(p->EA.img, &p->EA.bits_per_pixel, &p->EA.line_length, &p->EA.endian);
}

void  ft_parse_WE(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;

	line += 2;
	while (*line == ' ')
		line++;
	p->WE.img = mlx_xpm_file_to_image(p->mlx, ft_strtrim(line, " "), &img_width, &img_height);
	p->WE.addr = mlx_get_data_addr(p->WE.img, &p->WE.bits_per_pixel, &p->WE.line_length, &p->WE.endian);
}

void  ft_parse_SO(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;

	line += 2;
	while (*line == ' ')
		line++;
	p->SO.img = mlx_xpm_file_to_image(p->mlx, ft_strtrim(line, " "), &img_width, &img_height);
	p->SO.addr = mlx_get_data_addr(p->SO.img, &p->SO.bits_per_pixel, &p->SO.line_length, &p->SO.endian);
}

void  ft_parse_SP(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;

	line += 2;
	while (*line == ' ')
		line++;
	p->SP.img = mlx_xpm_file_to_image(p->mlx, ft_strtrim(line, " "), &img_width, &img_height);
	p->SP.addr = mlx_get_data_addr(p->SP.img, &p->SP.bits_per_pixel, &p->SP.line_length, &p->SP.endian);
}

void  ft_parse_NO(t_param *p, char *line)
{
	int		img_width;
	int 	img_height;

	line += 2;
	while (*line == ' ')
		line++;
	p->NO.img = mlx_xpm_file_to_image(p->mlx, ft_strtrim(line, " "), &img_width, &img_height);
	p->NO.addr = mlx_get_data_addr(p->NO.img, &p->NO.bits_per_pixel, &p->NO.line_length, &p->NO.endian);
}

int	ft_checking_all(t_param *p)
{
	if (p->NO.img && p->EA.img && p->WE.img && p->SO.img && p->scH != -1 && p->scW != -1 && p->F != -1 && p->C != -1)
		return (1);
	return (0);
}
int ft_parser(t_param *p, char *line)
{
	if (line[0] == 'R')
		ft_parse_resolution(p, line);
	else if (line[0] == 'F')
		ft_parse_floor(p, line);
	else if (line[0] == 'C')
		ft_parse_ceil(p, line);
	else if (line[0] == 'N' && line[1] == 'O')
		ft_parse_NO(p, line);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_parse_SO(p, line);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_parse_WE(p, line);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_parse_EA(p, line);
	if	(ft_checking_all(p))
		return (1);
	return (0);
	
}

int main()
{
	t_param p;
	char *line;
	int fd;
	t_data *mapa;

	ft_init(&p);
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!(ft_checking_all(&p)))
			ft_parser(&p, line);
	}
	return (0);
}
