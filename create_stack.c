#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	if (size <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->tab = malloc(size * sizeof(int));
	if (!(stack->tab))
		return (free(stack), NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

int	push_stack(t_stack *s, int value)
{
	if ((s->size - 1) == s->top)
		return (0);
	s->tab[++(s->top)] = value;
	return (1);
}

int	pop(t_stack *s)
{
	if (s->top == -1)
		return (0);
	(s->top)--;
	return (1);
}

int	search_stack(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->tab[i] == value)
			return (1);
		i++;
	}
	return (0);
}

t_stack	*destroy_stack(t_stack *a)
{
	free(a->tab);
	free(a);
	return (NULL);
}
