/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe_ctor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:43:05 by afeuerst          #+#    #+#             */
/*   Updated: 2017/05/30 15:12:48 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_fill_array(t_wireframe *const wf, const char *const path)
{
	char		*file;

	file = get_content_file(path);
	if (!file)
	{
		free(wf);
		exiting("No file found.\n", 1);
	}
	write(1, file, ft_strlen(file));
}

void			*wf_ctor(const void *const self, ...)
{
	va_list		args;
	t_wireframe	*new;

	va_start(args, self);
	new = malloc(sizeof(t_wireframe));
	if (!new)
		return (NULL);
	new->self = self;
	ft_fill_array(new, va_arg(args, char*));
	va_end(args);
	return (new);
}
