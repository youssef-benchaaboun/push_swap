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

int	index_nums(t_stack a)
{
	
}