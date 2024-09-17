/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:01:25 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/08 21:11:31 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_point	*create_point(double x, double y, double z, int color)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x = (x - y) * cos(M_PI / 5);
	new->y = (x + y) * sin(M_PI / 5) - z;
	new->color = color;
	return (new);
}

double	find_scale(t_matrix *mat)
{
	t_point	*min_p;
	t_point	*max_p;
	double	scale;

	min_p = min_border(mat, 0, -1 * ft_atoi(mat->rows[0][0]) * mat->z_scale);
	if (!min_p)
		return (0);
	max_p = max_border(mat, 0, -1 * ft_atoi(mat->rows[0][0]) * mat->z_scale);
	if (!max_p)
	{
		free(min_p);
		return (0);
	}
	scale = fmin((DISPLAY_X * WINDOW_X / (max_p->x - min_p->x)),
			(DISPLAY_Y * WINDOW_Y / (max_p->y - min_p->y)));
	free(min_p);
	free(max_p);
	return (scale);
}

int	find_center_x(t_matrix *mat, double scale)
{
	t_point	*min_p;
	t_point	*max_p;
	double	center_x;

	min_p = min_border(mat, 0, -1 * ft_atoi(mat->rows[0][0]) * mat->z_scale);
	if (!min_p)
		return (0);
	max_p = max_border(mat, 0, -1 * ft_atoi(mat->rows[0][0]) * mat->z_scale);
	if (!max_p)
	{
		free(min_p);
		return (0);
	}
	center_x = (WINDOW_X / 2) - (max_p->x * scale - min_p->x * scale) / 2
		- min_p->x * scale;
	free(min_p);
	free(max_p);
	return ((int)round(center_x));
}

int	find_center_y(t_matrix *mat, double scale)
{
	t_point	*min_p;
	t_point	*max_p;
	double	center_y;

	min_p = min_border(mat, 0, -1 * ft_atoi(mat->rows[0][0]) * mat->z_scale);
	if (!min_p)
		return (0);
	max_p = max_border(mat, 0, -1 * ft_atoi(mat->rows[0][0]) * mat->z_scale);
	if (!max_p)
	{
		free(min_p);
		return (0);
	}
	center_y = (WINDOW_Y / 2) - (max_p->y * scale - min_p->y * scale) / 2
		- min_p->y * scale;
	free(min_p);
	free(max_p);
	return ((int)round(center_y));
}
