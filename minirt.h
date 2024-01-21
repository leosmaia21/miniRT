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

typedef struct s_token{
	char	*type;
	float	a_lighting;
	int		a_rgb[3];
	float	c_xyz[3];
	float	c_orientation[3];
	float	c_fov;
	float	l_xyz[3];
	float	l_brightness;
	float	sp_xyz[3];
	float	sp_diameter;
	int		sp_rgb[3];
	float	pl_xyz[3];
	float	pl_vector[3];
	int		pl_rgb[3];
	float	cy_xyz[3];
	float	cy_vector[3];
	float	cy_diameter;
	float	cy_height;
	int		cy_rgb[3];
}	t_token;


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


t_list *getlines(int fd);
float	ft_atof(const char *s);
t_list	*verifytokens(t_list *list);
int 	checkifint(char *str,int range, int lower, int upper);
void	freejoin(char **s);
double	map(double value, t_range *in, t_range *out);
int		bye(t_vars *vars);

#endif // !MINIRT_H
