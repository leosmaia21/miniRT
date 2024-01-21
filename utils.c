/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:01:03 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/12/19 20:41:01 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	map(double value, t_range *in, t_range *out)
{
	return ((value - in->min) * (out->max - out->min) / (in->max - in->min));
}

void freejoin(char **s)
{
	char	**x;
	int		i;
	
	i = 0;
	x = s;
	if (!x)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(x);
}

float	ft_atof(const char *s)
{
	float	a;
	int		e;
	int		negative;

	a = 0.0;
	e = 0;
	negative = *s == '-';
	if (*s == '-')
		s++;
	while (*s != '\0' && ft_isdigit(*s))
		a = a * 10.0 + (*s++ - '0');
	if (*s++ == '.')
	{
		while (*s != '\0' && ft_isdigit(*s))
		{
			a = a * 10.0 + (*s++ - '0');
			e++;
		}
	}
	a = a * (1.0 / pow(10, e));
	if (negative)
		a *= -1;
	return (a);
}

int checkifint(char *str,int range, int lower, int upper)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if (i == 0 && str[i] == '-')
			continue;
		else if (!ft_isdigit(str[i]))
			return (0);
	}
	if (range)
	{
		if (ft_atoi(str) <= upper && ft_atoi(str) >= lower)
			return (1);
		return (0);
	}
	return (1);
}

int	bye(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}
