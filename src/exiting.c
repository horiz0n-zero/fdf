/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:49:19 by afeuerst          #+#    #+#             */
/*   Updated: 2017/05/30 14:53:03 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exiting(const char *const error, const int status)
{
	if (error)
		write(2, error, ft_strlen(error));
	exit(status);
}
