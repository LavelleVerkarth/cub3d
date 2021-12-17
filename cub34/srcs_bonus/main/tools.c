/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:10 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:12:11 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *s)
{
	printf("%s", s);
	exit(1);
}

void	error2(char *s1, char *s2)
{
	printf("%s", s1);
	printf("%s\n", s2);
	exit(1);
}

int	close_all(int keycode, t_all *cub)
{
	(void)cub;
	(void)keycode;
	exit(0);
}
