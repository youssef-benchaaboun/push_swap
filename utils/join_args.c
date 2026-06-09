/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:42:06 by stelescu          #+#    #+#             */
/*   Updated: 2026/06/08 00:49:36 by stelescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*new_arg(char **av, int ac, char *new_str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			new_str[k++] = av[i][j++];
		if (i < ac - 1)
			new_str[k++] = ' ';
		i++;
	}
	new_str[k] = '\0';
	return (new_str);
}

char	*join_args(char **av, int ac)
{
	char	*result;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	while (i < ac)
	{
		total_len += ft_strlen(av[i]);
		total_len++;
		i++;
	}
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	result = new_arg(av, ac, result);
	return (result);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
