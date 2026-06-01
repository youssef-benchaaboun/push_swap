#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	if (nb == 1)
		return (1);
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_find_sqrt(int nb)
{
	while(ft_sqrt(nb) == 0)
		nb++;
	return(ft_sqrt(nb));
}

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	size;

	i = 0;
	if (min >= max)
		return (NULL);
	size = (max - min);
	range = (int *) malloc((size) * sizeof(int));
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

void	ft_coordinate(t_stack *a)
{
	int	i;
	int	j;
	int	index_value;

	i = 0;
	index_value = 0;
	while (a->tab[i])
	{
		j = i + 1;
		while (a->tab[j])
		{
			if (a->tab[j] < a->tab[i])
				a->coord_value[j] = index_value;
		}
		index_value++;
		i++;
	}
}