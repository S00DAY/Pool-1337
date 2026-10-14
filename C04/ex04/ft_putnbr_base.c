/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:59:54 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/23 11:48:34 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_base(char *base)
{
	int	j;
	int	a;

	j = 0;
	while (base[j])
	{
		if (base[j] == '-' || base[j] == '+')
			return (0);
		a = j + 1;
		while (base[a])
		{
			if (base[a] == base[j])
				return (0);
			a++;
		}
		j++;
	}
	if (j < 2)
		return (0);
	return (j);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			blen;

	blen = check_base(base);
	if (blen == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= blen)
		ft_putnbr_base(n / blen, base);
	write(1, &base[n % blen], 1);
}
