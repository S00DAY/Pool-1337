/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:04:42 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/27 11:36:38 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i != nb)
	{
		if ((nb % i == 0) && (i != nb || i != 1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	isp;
	int	n;

	n = nb;
	isp = 0;
	while (isp != 1)
	{
		isp = ft_is_prime(n);
		if (isp == 1)
			return (n);
		if (isp == 0)
			n = n + 1;
	}
	return (n);
}
