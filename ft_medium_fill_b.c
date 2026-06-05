#include "push_swap.h"

static int	find_chunk_index(t_stack *a, int range_max)
{
	int	up;
	int	down;

	up = a->top;
	down = 0;
	while (down <= up)
	{
		if (a->tab[up] < range_max)
			return (up);
		if (a->tab[down] < range_max)
			return (down);
		up--;
		down++;
	}
	return (-1);
}

static void	move_chunk_top(t_stack *a, t_benchmark *bench, int idx)
{
	int	ra_cost;
	int	rra_cost;

	ra_cost = a->top - idx;
	rra_cost = idx + 1;
	if (ra_cost <= rra_cost)
	{
		while (a->top - idx > 0)
		{
			rotate_stack(a, 'a');
			bench->ra++;
			idx++;
		}
	}
	else
	{
		while (idx >= 0)
		{
			re_rotate_stack(a, 'a');
			bench->rra++;
			idx--;
		}
	}
}

void	medium_fill_b(t_stack *a, t_stack *b, t_benchmark *bench, int s)
{
	int	bucket_size;
	int	range_max;
	int	close_idx;

	bucket_size = ft_find_sqrt(s);
	if (bucket_size <= 0)
		bucket_size = 1;
	range_max = bucket_size;
	close_idx = find_chunk_index(a, range_max);
	while (a->top > -1)
	{
		close_idx = find_chunk_index(a, range_max);
		if (close_idx == -1)
			break ;
		move_chunk_top(a, bench, close_idx);
		push_in(a, b, 'b');
		bench->pb++;
		if (b->top + 1 >= range_max)
			range_max += bucket_size;
	}
}
