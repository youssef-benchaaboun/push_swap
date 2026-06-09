#include "../../push_swap.h"

static void	max_rb(t_stack *b, t_benchmark *bench, int n)
{
	while (n-- > 0)
	{
		if (swap_to_top(b, bench) == 1)
			return ;
		rotate_stack(b, 'b');
		bench->rb++;
	}
}

static void	max_rrb(t_stack *b, t_benchmark *bench, int n)
{
	while (n-- > 0)
	{
		if (swap_to_top(b, bench) == 1)
			return ;
		re_rotate_stack(b, 'b');
		bench->rrb++;
	}
}

void	max_to_top(t_stack *b, t_benchmark *bench, int max_idx)
{
	int	rotate;
	int	re_rotate;

	rotate = b->top - max_idx;
	re_rotate = max_idx + 1;
	if (rotate <= re_rotate)
		max_rb(b, bench, rotate);
	else
		max_rrb(b, bench, re_rotate);
}
