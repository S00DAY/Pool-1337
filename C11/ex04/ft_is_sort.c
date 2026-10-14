/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:53:17 by soulkhat          #+#    #+#             */
/*   Updated: 2026/08/06 16:53:27 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_asc;
	int	is_desc;

	if (!tab || !f || length <= 1)
		return (1);
	i = 0;
	is_asc = 1;
	is_desc = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			is_asc = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			is_desc = 0;
		i++;
	}
	return (is_asc || is_desc);
}
