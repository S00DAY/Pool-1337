/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:12:05 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/15 16:35:26 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	write_comb(char i, char j)
{
	char	d;
	char	dg;

	d = i % 10 + '0';
	dg = i / 10 + '0';
	write(1, &dg, 1);
	write(1, &d, 1);
	write(1, " ", 1);
	d = j % 10 + '0';
	dg = j / 10 + '0';
	write(1, &dg, 1);
	write(1, &d, 1);
	if (!(i == 98 && j == 99))
		write(1, ", ", 2);
	return (0);
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			write_comb(i, j);
			j++;
		}
		i++;
	}
}
