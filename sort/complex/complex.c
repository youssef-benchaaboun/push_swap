#include "../../push_swap.h"

void	rotation(t_stack *b, t_benchmark *bench, int min)
{
	int	rotation;

	rotation = better_cost(b, min);
	while (b->tab[b->top] != min && b->tab[b->top] != min - 1)
	{
		if (rotation)
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
}

void	move_back(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	min;

	min = b->top;
	while (b->top > -1)
	{
		rotation(b, bench, min);
		push_in(b, a, 'a');
		(bench->pa)++;
		if (a->top >= 1 && a->tab[a->top] > a->tab[a->top - 1])
		{
			swap_stack(a, 'a');
			(bench->sa)++;
		}
		while (b->top > -1 && !search_stack(b, min))
			min--;
	}
}

void	radix_sort(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	base;
	int	upper;
	int	bottom;
	int	i;
	int	digit;

	ft_coordinate(a);
	base = better_base(a->size);
	upper = base / 2;
	bottom = upper - 1;
	i = 2;
	while (a->top > -1)
	{
		digit = mosts_digit(a->tab[a->top], base);
		if (digit == upper)
		{
			push_in(a, b, 'b');
			(bench->pb)++;
		}
		else if (digit == bottom)
		{
			push_in(a, b, 'b');
			rotate_stack(b, 'b');
			(bench->pb)++;
			(bench->rb)++;
		}
		else
		{
			rotate_stack(a, 'a');
			(bench->ra)++;
		}
		if (bench->pb >= i * base)
		{
			bottom--;
			upper++;
			i += 2;
		}
	}
	move_back(a, b, bench);
}
