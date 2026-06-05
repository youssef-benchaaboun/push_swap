#include "push_swap.h"

void	medium_fill_b(t_stack *a, t_stack *b, t_benchmark *bench, int s)
{
	int	bucket_size;
	int	range_max;

	bucket_size = ft_find_sqrt(s);
	if (bucket_size <= 0)
		bucket_size = 1;
	range_max = bucket_size;
	while (a->top > -1)
	{
		if (a->tab[a->top] < range_max)
		{
			push_in(a, b, 'b');
			(bench->pb)++;
			if (b->top > 0 && b->tab[b->top] < bucket_size / 2)
			{
				rotate_stack(b, 'b');
				(bench->rb)++;
			}
		}
		else
		{
			rotate_stack(a, 'a');
			(bench->ra)++;
		}
		if (b->top + 1 >= range_max)
			range_max += bucket_size;
	}
}
