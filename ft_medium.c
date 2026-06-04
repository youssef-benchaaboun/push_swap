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
			if (b->top > 0 && (b->tab[b->top] < bucket_size / 2))
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
		if (b->top >= range_max - 1 && b->top < s)
			range_max *= 2;
	}
}

void	medium_phase_three(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	max;
	int	i;
	int	rotations;

	while (b->top > -1)
	{
		max = b->tab[b->top];
		i = 0;
		rotations = 0;
		while (i <= b->top)
		{
			if (b->tab[i] > max)
			{
				max = b->tab[i];
				rotations = i;
			}
			i++;
		}
		while (b->tab[b->top] != max)
		{
			if (rotations <= b->top / 2)
			{
				rotate_stack(b, 'b');
				(bench->rb)++;
			}
			else
			{
				re_rotate_stack(b, 'b');
				(bench->rrb)++;
			}
		}
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
