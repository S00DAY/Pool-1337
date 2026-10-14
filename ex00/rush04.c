/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:01:47 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:00 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	a;
	int	b;

	if (x <= 0 || y <= 0)
		return ;
	a = 1;
	while (a <= y)
	{
		b = 1;
		while (b <= x)
		{
			if ((a == 1 && b == 1) || (a == y && b == x && a > 1 && b > 1))
				ft_putchar('A');
			else if ((a == 1 && b == x) || (a == y && b == 1))
				ft_putchar('C');
			else if (a == 1 || a == y || b == 1 || b == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}
