#include "../../push_swap.h"

int	better_base(int nb)
{
	int	i;

	i = 1;
	while (i * i + i < nb)
		i++;
	return (i + 1);
}

int	mosts_digit(int n, int base)
{
	int	div;

	div = n / base;
	return (div);
}

int	better_cost(t_stack *b, int min)
{
	int	i;

	i = b->top;
	while (i >= 0 && b->tab[i] != min)
		i--;
	if (i < 0)
		return (1);
	return ((b->top - i) <= i);
}
