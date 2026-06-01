#include "push_swap.h"

int	ft_stack_min(t_stack *a)
{
	int	min;
	int	i;

	i = 0;
	min = a->tab[a->top];
	while (i <= a->top)
	{
		if (a->tab[i] < min)
		{
			min = a->tab[i];
		}
		i++;
	}
	return (min);
}

void	ft_simple(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	min;

	min = ft_stack_min(a);
	while (a->top > -1)
	{
		if (a->tab[a->top] == min)
		{
			push_in(a, b, 'b');
			(bench->pb)++;
			if (a->top > -1)
				min = ft_stack_min (a);
		}
		else
		{
			rotate_stack(a, 'a');
			(bench->ra)++;
		}
	}
	while (b->top > -1)
	{
		push_in(b, a, 'a');
		(bench->pa)++;
	}
}
