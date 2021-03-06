/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:42:00 by lverkart          #+#    #+#             */
/*   Updated: 2021/08/24 17:30:44 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_digits(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] != 0)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}
