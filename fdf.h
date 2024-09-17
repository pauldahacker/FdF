/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:02:01 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/08 21:59:29 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ESC 53
# define UP 126
# define DOWN 125

# define MAX_Y 10800

# define NEWLINE '\n'
# define BYTE_START 1
# define WINDOW_X 1600
# define WINDOW_Y 900
# define FDF_EXTENSION ".fdf"

# define DISPLAY_X 0.8
# define DISPLAY_Y 0.8

# define BASE_Z_SCALE 0.1
# define Z_OFFSET 0.1
# define ANG M_PI_4

# define EGYPT_BLUE 0x5F9EA0
# define LIGHT_BLUE 0x8DA399

# include "mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_point
{
	int			color;
	double		x;
	double		y;
}				t_point;

typedef struct s_matrix
{
	int			x;
	int			y;
	double		z_scale;
	char		***rows;
}				t_matrix;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	double		scale;
	int			center_x;
	int			center_y;
	t_matrix	*mat;
}				t_data;

typedef struct s_vars
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
}				t_vars;

// check.c
void			check_args(int argc, char **argv);

// color.c
int				get_color(char *s, int base_color);

// controls.c
int				on_destroy(t_vars *vars);
int				on_keypress(int keysym, t_vars *vars);

// draw_utils.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point			*create_point(double x, double y, double z, int color);
double			find_scale(t_matrix *mat);
int				find_center_x(t_matrix *mat, double scale);
int				find_center_y(t_matrix *mat, double scale);

// draw.c
void			draw_right(t_data *img, t_matrix *mat, int x, int y);
void			draw_down(t_data *img, t_matrix *mat, int x, int y);
void			draw_matrix(t_vars *vars, t_data img, t_matrix *mat);

// ft.c
int				ft_space(char c);
char			**ft_split(char const *s, char c);

// gnl_utils.c
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *str, int c);
char			*tochr(char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);

// gnl.c
char			*destroy(char **s);
char			*get_next_line(int fd);

// matrix_utils.c
void			ft_free(char **res);
int				ft_atoi(const char *str);
void			*destroy_rows(char ***rows, int y);
void			*destroy_matrix(t_matrix *mat);
t_matrix		*init_matrix(void);

// matrix.c
t_point			*create_border(double x, double y);
t_point			*min_border(t_matrix *mat, double xmin, double ymin);
t_point			*max_border(t_matrix *mat, double xmax, double ymax);
t_matrix		*make_matrix(int fd);

#endif
