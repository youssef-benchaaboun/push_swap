#include "push_swap.h"

void	medium_phase_one(t_stack *a, t_stack *b, t_benchmark *bench, int s)
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

int	find_max_index(t_stack *b)
{
	int	max;
	int	max_idx;
	int	i;

	max = b->tab[0];
	max_idx = 0;
	i = 1;
	while (i <= b->top)
	{
		if (b->tab[i] > max)
		{
			max = b->tab[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

void	max_to_top(t_stack *b, t_benchmark *bench, int max_idx)
{
	int	rotate;
	int	re_rotate;

	rotate = b->top - max_idx;
	re_rotate = max_idx + 1;
	if (rotate <= re_rotate)
	{
		while (rotate > 0)
		{
			rotate_stack(b, 'b');
			(bench->rb)++;
			rotate--;
		}
	}
	else
	{
		while (re_rotate > 0)
		{
			re_rotate_stack(b,'b');
			(bench->rrb)++;
			re_rotate--;
		}
	}
}

void	medium_phase_three(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	max_i;
	
	while (b->top > -1)
	{
		max_i = find_max_index(b); 
		max_to_top(b, bench, max_i);
		push_in(b, a, 'a');
		(bench->pa)++;
	}
}

void	ft_medium(t_stack *a, t_stack *b, t_benchmark *bench, int nb_count)
{
	if (!a || !b || nb_count <= 0)
		return ;
	if (nb_count <= 1)
		return ;
	medium_phase_one(a, b, bench, nb_count);
	medium_phase_three(a, b, bench);
}
