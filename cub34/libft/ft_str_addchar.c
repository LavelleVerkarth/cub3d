/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:01 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:14:02 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_addchar(char *tmp, char buffer)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(tmp);
	res = malloc(sizeof(char) * (len + 2));
	while (len > 0)
	{
		res[i] = tmp[i];
		i++;
		len--;
	}
	res[i] = buffer;
	i++;
	res[i] = '\0';
	if (tmp)
		free(tmp);
	return (res);
}
