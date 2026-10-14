/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:49:43 by soulkhat          #+#    #+#             */
/*   Updated: 2026/08/06 16:50:48 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*p;

	if (!tab || !f || length <= 0)
		return (NULL);
	p = (int *)malloc(sizeof(int) * length);
	if (!p)
		return (NULL);
	i = 0;
	while (i < length)
	{
		p[i] = f(tab[i]);
		i++;
	}
	return (p);
}
