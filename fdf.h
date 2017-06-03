/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:39:43 by afeuerst          #+#    #+#             */
/*   Updated: 2017/05/30 15:00:53 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>

# ifndef true
#  define true (int)1
#  define false (int)0
#  define bool int
# endif

typedef struct		s_class
{
	size_t			size;
	void			*(*ctor)(const void *const self, ...);
	void			(*dtor)(void *const self);
}					t_class;

typedef struct		s_wireframe
{
	const void		*self;
	int				*array;
	int				array_x;
	int				array_y;
}					t_wireframe;

void				*wf_ctor(const void *const self, ...);
void				wf_dtor(void *const self);

void				exiting(const char *const error, const int status);
size_t				ft_strlen(const char *const str);
char				*get_content_file(const char *const path);
char				*ft_strjoin(const char *s1, const char *s2);
#endif
