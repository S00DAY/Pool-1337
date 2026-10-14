/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 09:36:37 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/30 11:38:32 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);

int	ft_atoi_base(char *str, char *base);

int	nlen(int nb, int tlen)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		nb = nb / tlen;
		len++;
	}
	return (len);
}

char	*int_to_base(int nb, char *base_to, int tlen)
{
	char	*str;
	long	n;
	int		size;

	size = nlen(nb, tlen);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	n = nb;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = base_to[0];
	while (n > 0)
	{
		size--;
		str[size] = base_to[n % tlen];
		n = n / tlen;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	tlen;
	int	flen;
	int	num;

	flen = check_base(base_from);
	tlen = check_base(base_to);
	if (flen < 2 || tlen < 2)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (int_to_base(num, base_to, tlen));
}
