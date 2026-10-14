/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:10:12 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/29 21:20:23 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		len;
	int		*p;

	if (min >= max)
		return (NULL);
	len = max - min;
	p = malloc(len * sizeof(int));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
