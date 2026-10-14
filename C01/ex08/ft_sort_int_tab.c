/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:41:47 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/16 13:50:16 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	hold;
	int	j;
	int	i;

	i = 1;
	while (i < size)
	{
		hold = tab[i];
		j = i - 1;
		while (j >= 0 && hold < tab[j])
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = hold;
		i++;
	}
}

