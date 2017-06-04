/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:23:07 by afeuerst          #+#    #+#             */
/*   Updated: 2017/06/04 18:11:30 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void					ft_color_image(t_wireframe *const wf)
{
	int						color;

	color = PIXEL(21, 37, 200);
	for (int x = 0; x < SWIDTH; x++)
	{
		for (int y = 0; y < SHEIGHT; y++)
		{
			wf->array[x * y] = color;
		}
	}
}

static void					ft_start(t_wireframe *const wf)
{
	void					*image;

	image = mlx_new_image(wf->mlx, SWIDTH, SHEIGHT);
	wf->array = (int*)mlx_get_data_addr(image, &wf->pixel_len, &wf->size_line, &wf->endian);
	ft_color_image(wf);
	mlx_put_image_to_window(wf->mlx, wf->win, image, 0, 0);
}

int							main(int argc, char **argv)
{
	void					*mlx;
	void					*win;
	static const t_class	object = {sizeof(t_wireframe), wf_ctor, wf_dtor};
	t_wireframe				*wireframe;

	if (argc < 2)
		exiting("Usage : fdf <file>\n", 1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, SWIDTH, SHEIGHT, *++argv);
	wireframe = object.ctor(&object, *argv, mlx, win);
	ft_start(wireframe);
	mlx_loop(mlx);
	return (0);
}
