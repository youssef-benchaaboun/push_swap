/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:43:46 by stelescu          #+#    #+#             */
/*   Updated: 2026/06/08 00:42:46 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_free_str(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_matrix(char **m, char *s, char c, int len)
{
	int	i;
	int	j;
	int	start;

	start = -1;
	i = 0;
	j = 0;
	while (i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == len))
		{
			m[j] = ft_substr(s, start, i - start);
			if (!(m[j]))
				return (ft_free_str(m, j));
			start = -1;
			j++;
		}
		i++;
	}
	m[j] = NULL;
	return (m);
}

char	**ft_split(char *s, char c)
{
	char	**m;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	m = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!m)
		return (NULL);
	return (ft_matrix(m, s, c, len));
}
