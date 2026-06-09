#include "../push_swap.h"

int	ft_error(t_stack *a, t_stack *b)
{
	if (a)
		destroy_stack (a);
	if (b)
		destroy_stack (b);
	write(2, "Error\n", 6);
	return (1);
}

int	ft_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->tab[i] < a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
