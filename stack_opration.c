#include "push_swap.h"

int	swap_stack(t_stack *a, char c)
{
	int	tmp;
	int	top;

	top = a->top;
	if (top < 1)
		return (0);
	tmp = a->tab[top];
	a->tab[top] = a->tab[top - 1];
	a->tab[top - 1] = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	return (1);
}

int	push_in(t_stack *src, t_stack *dest, char c)
{
	int	top;

	top = src->top;
	if (top < 0)
		return (0);
	push_stack(dest, src->tab[top]);
	pop(src);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	return (1);
}

int	re_rotate_stack(t_stack *a, char c)
{
	int	i;
	int	last;

	i = 0;
	if (a->top < 1)
		return (0);
	last = a->tab[0];
	while (i < a->top)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[a->top] = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	return (1);
}

int	rotate_stack(t_stack *a, char c)
{
	int	first;
	int	i;

	i = a->top;
	if (a->top < 1)
		return (0);
	first = a->tab[a->top];
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[0] = first;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	return (1);
}
