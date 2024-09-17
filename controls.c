/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:00:33 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/08 21:00:35 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars->mlx_ptr);
	destroy_matrix(vars->data.mat);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_vars *vars)
{
	(void)vars;
	if (keysym == ESC)
		on_destroy(vars);
	if (keysym == UP)
	{
		vars->data.mat->z_scale += Z_OFFSET;
		draw_matrix(vars, vars->data, vars->data.mat);
	}
	if (keysym == DOWN)
	{
		vars->data.mat->z_scale -= Z_OFFSET;
		draw_matrix(vars, vars->data, vars->data.mat);
	}
	return (0);
}
