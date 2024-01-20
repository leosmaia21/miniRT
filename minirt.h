/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:56:52 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/12/19 20:44:41 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#define SIZE 500

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_range{
	double min;
	double max;
}	t_range;

typedef enum s_parsertoken{
	A, C, L, sp, pl, cy
} t_parsertoken;

typedef struct s_a{
	char	*type;
	float	lighting;
	int		rgb[3];
}	t_a;

typedef struct s_c{
	char	*type;
	float	xyz[3];
	float	orientation[3];
	float	fov;
}	t_c;

typedef struct s_l{
	char	*type;
	float	xyz[3];
	float	light;
}	t_l;

typedef struct s_sp{
	char	*type;
	float	xyz[3];
	float	diameter;
	int		rgb[3];
}	t_sp;

typedef struct s_pl{
	char	*type;
	float	xyz[3];
	float	norm_vector[3];
	int		rgb[3];
}	t_pl;

typedef struct s_cy{
	char	*type;
	float	xyz[3];
	float	norm_vector[3];
	float	diameter;
	float	height;
	int		rgb[3];
}	t_cy;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_vars;

typedef struct s_minirt{
	int		name;
	double	zoom;
	int		loops;
	t_vars	vars;
}	t_minirt;


t_list *getlines(char * filename);
float	ft_atof(const char *s);
void	freejoin(char **s);
double	map(double value, t_range *in, t_range *out);
int		bye(t_vars *vars);

#endif // !MINIRT_H
