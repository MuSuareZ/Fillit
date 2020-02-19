/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:56:54 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/16 12:23:20 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** FUNCTION ERRNO
** Can be used to print out error messages at any point of the program.
** Easiest way to call it is to put it in a
**return statement. I.e return(errno(1));
*/

int		errno(void)
{
	ft_putstr("error\n");
	return (-1);
}

char	*please_read(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	char	*str;
	int		ret;

	str = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = temp;
		}
	}
	return (str);
}

void	start_solving(t_data *tetris, t_map *mappi)
{
	reset_map(mappi, ft_square(tetris->n_hashes, mappi));
	while (!(solve(tetris, mappi)))
		reset_map(mappi, mappi->map_size++);
	print_map(mappi->map);
}

int		main(int ac, char **av)
{
	size_t	mover;
	t_data	tetris;
	int		fd;
	t_map	mappi;

	if (ac != 2)
		write(1, "usage: ./fillit file_name\n", 26);
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (errno());
		tetris.str = please_read(fd);
		tetris.len = ft_strlen(tetris.str);
		mover = 0;
		while (mover <= tetris.len)
		{
			if (check_shapes(tetris.str + mover, &tetris) != 0 ||
			validate_square(&tetris) != 0)
				return (errno());
			mover += 21;
		}
		start_solving(&tetris, &mappi);
	}
	return (0);
}
