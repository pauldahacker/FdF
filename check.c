/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:29:36 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/08 22:00:05 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_readable(char *file)
{
	int	fd;
	int	flag;

	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		flag = 0;
	else
		flag = 1;
	close(fd);
	return (flag);
}

int	is_format(char *str, char *ext)
{
	int	len;
	int	formatlen;
	int	i;

	len = ft_strlen(str);
	formatlen = ft_strlen(ext);
	i = 1;
	while (str[len - i] && ext[formatlen - i])
	{
		if (str[len - i] != ext[formatlen - i])
			return (0);
		i++;
	}
	return (1);
}

void	handle_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "Arguments ", 10);
		handle_error();
	}
	else if (!is_readable(argv[1]))
	{
		write(STDERR_FILENO, "Read ", 5);
		handle_error();
	}
	else if (!is_format(argv[1], FDF_EXTENSION))
	{
		write(STDERR_FILENO, "Format ", 7);
		handle_error();
	}
}
