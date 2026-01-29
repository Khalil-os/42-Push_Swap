/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:02:00 by kriad             #+#    #+#             */
/*   Updated: 2026/01/26 19:38:05 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*word_dup(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 2) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start <= end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **res, int k)
{
	while (k >= 0)
		free(res[k--]);
	free(res);
	return (NULL);
}

static int	split2(char **res, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			res[k] = word_dup(s, i, j - 1);
			if (!res[k])
				return (free_all(res, k), 0);
			k++;
			i = j;
		}
		else
			i++;
	}
	res[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!split2(res, s, c))
		return (NULL);
	return (res);
}
