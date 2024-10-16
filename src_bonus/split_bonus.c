/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:42:15 by rafnasci          #+#    #+#             */
/*   Updated: 2024/06/05 14:42:21 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			wordcount++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
	}
	return (wordcount);
}

static void	ft_free(char **rep)
{
	int	i;

	i = 0;
	while (rep[i] != NULL)
	{
		free(rep[i]);
		i++;
	}
	free(rep);
}

static char	*ft_lettercount(char const *s, char c, char **rep, int word)
{
	int	i;
	int	len;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	rep[word] = ft_calloc(i + 1, sizeof(char));
	if (!rep[word])
	{
		ft_free(rep);
		return (NULL);
	}
	len = 0;
	while (len < i)
	{
		rep[word][len] = s[len];
		len++;
	}
	return (rep[word]);
}

static char	**ft_initt(char const *s, char c)
{
	int		wordcount;
	int		i;
	char	**rep;

	wordcount = 1;
	i = 0;
	rep = ft_calloc(ft_wordcount(s, c) + 2, sizeof(char *));
	if (!rep)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			if (!ft_lettercount(&s[i], c, rep, wordcount))
				return (NULL);
			while (s[i] && s[i] != c)
				i++;
			wordcount++;
		}
	}
	return ((rep));
}

char	**ft_splitt(char const *s, char c)
{
	char	**rep;

	if (!s)
		return (NULL);
	rep = ft_initt(s, c);
	if (!rep)
		return (NULL);
	rep[0] = malloc (sizeof(char));
	if (!rep[0])
		return (ft_free(rep), NULL);
	rep[0][0] = '\0';
	return (rep);
}
