#include "../push_swap.h"

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
	while (ft_sqrt(nb) == 0)
		nb++;
	return (ft_sqrt(nb));
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

static int	count_smaller(t_stack *a, int idx)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j <= a->top)
	{
		if (a->tab[j] < a->tab[idx])
			count++;
		j++;
	}
	return (count);
}

void	ft_coordinate(t_stack *a)
{
	int	i;
	int	*temp;

	temp = malloc((a->top + 1) * sizeof(int));
	if (!temp)
		return ;
	i = 0;
	while (i <= a->top)
	{
		temp[i] = count_smaller(a, i);
		i++;
	}
	i = 0;
	while (i <= a->top)
	{
		a->tab[i] = temp[i];
		i++;
	}
	free(temp);
}
