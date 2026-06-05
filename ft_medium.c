#include "push_swap.h"


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

int	swap_to_top(t_stack *b, t_benchmark *bench)
{
	int	flag;

	flag = 0;
	if (find_max_index(b) == b->top - 1)
	{
		swap_stack(b, 'b');
		(bench->sb)++;
		flag = 1;
	}
	return (flag);
}

void	medium_sort_a(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	max_i;
	
	while (b->top > -1)
	{
		max_i = find_max_index(b);
		if (max_i == b->top - 1)
			swap_to_top(b, bench);
		else if (max_i != b->top)
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
	medium_fill_b(a, b, bench, nb_count);
	medium_sort_a(a, b, bench);
}
