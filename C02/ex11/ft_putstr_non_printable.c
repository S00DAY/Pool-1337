/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:43:46 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/19 16:01:23 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mtba3a(char *tab)
{
	int		j;
	char	arr;

	j = 0;
	while (j <= 1)
	{
		if (tab[j] <= 9)
			arr = tab[j] + '0';
		else
			arr = tab[j] - 10 + 'a';
		write(1, &arr, 1);
		j++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			tab[2];
	unsigned char	a;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			a = (unsigned char)str[i];
			tab[1] = a % 16;
			tab[0] = a / 16;
			write(1, "\\", 1);
			mtba3a(tab);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
