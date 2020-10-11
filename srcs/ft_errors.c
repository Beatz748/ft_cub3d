/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:32:41 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:07:49 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_error(int i)
{
	if (i == 1)
		write(1, "Let's try to enter correct number of arguments ?\n", 50);
	if (i == 2)
		write(1, "Need extension .cub\n", 21);
	if (i == 3)
		write(1, "Not valid textures\n", 20);
	if (i == 4)
		write(1, "Need extension .xpm\n", 21);
	if (i == 5)
		write(1, "Not valid resolution\n", 22);
	if (i == 6)
		write(1, "Put only 1 player!\n", 20);
	if (i == 7)
		write(1, "Not valid map !\n", 17);
	if (i == 8)
		write(1, "Enter correct arguments\n", 25);
	if (i == 9)
		write(1, "I can't open file =(\n", 22);
	if (i == 10)
		write(1, "Incorrect colors!\n", 19);
	exit(-1);
}
