/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:23:07 by afeuerst          #+#    #+#             */
/*   Updated: 2017/05/30 15:19:10 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int							main(int argc, char **argv)
{
	void					*mlx;
	void					*win;
	static const t_class	object = {sizeof(t_wireframe), wf_ctor, wf_dtor};
	t_wireframe				*wireframe;

	if (argc < 2)
		exiting("Usage : fdf <file>\n", 1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, *++argv);
	wireframe = object.ctor(&object, *argv);
	mlx_loop(mlx);
	return (0);
}
