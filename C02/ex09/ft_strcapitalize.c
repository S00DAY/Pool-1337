/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:09:45 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/21 13:43:31 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	mktaba(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		else if (i > 0 && !mktaba(str[i - 1])
			&& (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		else if (i > 0 && (str[i] >= 65 && str[i] <= 90)
			&& mktaba(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
