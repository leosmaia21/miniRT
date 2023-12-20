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

typedef struct s_range{
	double min;
	double max;
}	t_range;

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


double	map(double value, t_range *in, t_range *out);
int		bye(t_vars *vars);

#endif // !MINIRT_H
