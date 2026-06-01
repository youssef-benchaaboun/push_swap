#include "push_swap.h"

int	count_buckets(int num)
{
	int j;

	j = 1;
	while (j < ft_find_sqrt(num))
		j++;
	return (j);
}

void	ft_medium(t_stack *a, t_stack *b, t_benchmark *bench, int nb_count)
{
	int	bucket_count;
	int range_max;
	int range_min;
	int i;

	i = 2;
	bucket_count = count_buckets(nb_count);
	range_max = ft_find_sqrt(nb_count) * i;
	range_min = ft_find_sqrt(nb_count);
	while (a->top > - 1)
	{
		if (a->tab[0] <= range_max && a->tab[0] >= range_min)
		{
			push_in(a, b, 'b');
			(bench->pb)++;
		}
		else
		{
			rotate_stack(a, 'a');
			(bench->ra)++;
		}
		if (b->top >= ft_find_sqrt(nb_count) && b->top < nb_count)
		{
			range_max *= 2;
			range_min *= 2;
		}
	}
}

//--medium --bench 5 4 3 2 1