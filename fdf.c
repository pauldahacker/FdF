/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:01:41 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/08 21:33:17 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	int			fd;
	t_matrix	*mat;

	check_args(argc, argv);
	fd = open(argv[1], O_RDONLY);
	mat = make_matrix(fd);
	if (!mat)
		return (1);
	vars.data.mat = mat;
	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
		return (1);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_X, WINDOW_Y, "FdF");
	if (!vars.win_ptr)
		return (free(vars.mlx_ptr), 1);
	vars.data.img = mlx_new_image(vars.mlx_ptr, WINDOW_X, WINDOW_Y);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &(vars.data.bpp),
			&(vars.data.line_length), &(vars.data.endian));
	draw_matrix(&vars, vars.data, vars.data.mat);
	mlx_hook(vars.win_ptr, 2, 1L << 0, &on_keypress, &vars);
	mlx_hook(vars.win_ptr, 17, 0, &on_destroy, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
