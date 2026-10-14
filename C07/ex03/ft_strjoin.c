/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:22:55 by soulkhat          #+#    #+#             */
/*   Updated: 2026/07/29 21:32:11 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strslen(int size, char **strs)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		len = len + j;
		i++;
	}
	return (len);
}

void	t3marhhhh(int size, char **strs, char *sep, char *res)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[a++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				res[a++] = sep[j++];
		}
		i++;
	}
	res[a] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		slen;
	int		splen;
	int		len;

	if (size <= 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	slen = strslen(size, strs);
	splen = 0;
	while (sep[splen])
		splen++;
	splen = splen * (size - 1);
	len = splen + slen + 1;
	res = malloc(len);
	if (res == NULL)
		return (NULL);
	t3marhhhh(size, strs, sep, res);
	return (res);
}
