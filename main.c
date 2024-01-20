/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:51:44 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/12/19 20:51:45 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "minirt.h"
#include <stdlib.h>



void	init(t_minirt *rt)
{
	rt->zoom = 1;
	rt->vars.mlx = mlx_init();
	rt->vars.win = mlx_new_window(rt->vars.mlx, SIZE, SIZE, "MiniRT");
	rt->vars.img = mlx_new_image(rt->vars.mlx, SIZE, SIZE);
	rt->vars.addr = mlx_get_data_addr(rt->vars.img, &rt->vars.bits_per_pixel,
			&rt->vars.line_length, &rt->vars.endian);
	// mlx_key_hook(minirt->vars->win, key_hook, minirt);
	// mlx_mouse_hook(minirt->vars->win, mouse_hook, minirt);
	// mlx_hook(minirt->vars->win, 17, 0, bye, minirt->vars);
}

int	main()
{
	// t_minirt rt

	t_list* t = getlines("teste");
	printf("%s", (char*)(t->content));
	t = t->next;
	printf("%s", (char*)(t->content));
	t = t->next;
	printf("%s", (char*)(t->content));
	t = t->next;
	printf("%s", (char*)(t->content));
	t = t->next;
	printf("%s", (char*)(t->content));
	t = t->next;
	printf("%s", (char*)(t->content));
	t = t->next;
	// printf("%s", (char*)(t->content));
	// t = t->next;

	// init(&rt);
	// mlx_loop(rt.vars.mlx);
	//
	// bye(&rt.vars);
	return (0);
}
