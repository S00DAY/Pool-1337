/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulkhat <soulkhat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:55:05 by soulkhat          #+#    #+#             */
/*   Updated: 2026/08/04 17:35:42 by soulkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	int	a;

	a = 0;
	while (charset[a])
	{
		if (charset[a] == c)
			return (1);
		a++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset) == 1)
			i++;
		if (str[i] && check_sep(str[i], charset) == 0)
			count++;
		while (str[i] && check_sep(str[i], charset) == 0)
			i++;
	}
	return (count);
}

char	*make_word(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (str[len] && check_sep(str[len], charset) == 0)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	arr = malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset) == 1)
			i++;
		if (str[i] && check_sep(str[i], charset) == 0)
		{
			arr[j++] = make_word(&str[i], charset);
			while (str[i] && check_sep(str[i], charset) == 0)
				i++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
